(* STERLING-Ag types *)
(*
datatype typ = 
  Int 
| Arrow of typ * typ 
  (* i.e., Arrow(argType, returnType) *)
| Prod of typ list 
  (* To be valid, the type list must have at least 2 elements. *)
  (* e.g., int * (int->int) is Prod([Int,Arrow(Int,Int)]) *)
| Sum of typ list 
  (* To be valid, the type list must have at least 1 element. *)
  (* e.g., int + (int x int) is Sum([Int,Prod([Int,Int])]) *)
| Var of string
  (* can only be used in a recursive type declaring this variable *)
| Rec of string * typ;

(* STERLING-Ag expressions *)
datatype expr = 
  IntExpr of int  
| VarExpr of string
| SuccExpr of expr 
  (* computes the successor of the int-type subexpression *)
| PredExpr of expr 
  (* computes the predecessor of the int-type subexpression *)
| FunExpr of string option * string option * typ * typ * expr
  (* i.e.: FunExpr(funName, paramName, paramType, returnType, bodyExpr) *)
  (* Valid FunExprs must have valid argument and return types annotated. *)
| ApplyExpr of expr * expr 
  (*i.e.: ApplyExpr(funExpr, argumentExpr) *)
| BeqExpr of expr * expr * expr * expr
  (* i.e. BeqExpr(testExpr1, testExpr2, toBranchExpr, elseBranchExpr) *)
| TupleExpr of expr list 
  (* Valid tuples must have at least 2 elements. *)
| LetExpr of string list * expr * expr
  (* e.g. let (x1,x2) = e in e' end is LetExpr(["x1", "x2"], e, e') *)
  (* Let expressions are only well typed if there are exactly as many variable 
     names as there are tuple elements.  During execution, the first variable is
     bound to the first tuple-element value, the second is bound to the second, 
     etc. *)
  (* Valid LetExprs must have at least 2 elements in their string lists *)
| SumExpr of int * expr * typ list 
  (* e.g.(in3 7):int+int+int, which injects the expression 7 into the 3rd 
     component of an int+int+int sum,  is SumExpr(3,IntExpr(7),[Int,Int,Int]) *)
  (* As with functions, the annotated type in a SumExpr must be valid *)
| CaseExpr of expr * (string * expr) list
  (* e.g., case e of in1 x=>e1 | in2 y=>e2 is CaseExpr(e,[("x",e1),("y",e2)]) *)
  (* Case expressions are well typed only if they define a case for every 
     possible injection index and no others.  During execution, if a value v 
     has been injected into index i, then the entire case expression steps to 
     the expression of the ith list element with its associated variable bound 
     to v. *)
| RollExpr of expr 
| UnrollExpr of expr;
*)

(* Amer Abdelaziz
    U25449742

    “I pledge my Honor that I have not
    cheated, and will not cheat, on this assignment.”

    This project extends onto the previous assignment and adds 
    more expressions and types, both functions take an expression and 
    one type checks it and the other evaluates it

    

  *)

  (* Type Checkers function takes an expression and produces a typ option *)

fun tc( e: expr) =
  let
    (* Using the list data structure to keep track of the functions and their types *)
    val Varst = []
    val SI = SOME Int

    (* Helper function to retrieve the type of the function *)
    fun vt(s: string option , (var ,t) :: Varst) = 
      if s = var then SOME (t) 
      else vt(s,Varst)
    | vt(_,nil) = NONE
    (* Helper size function *)
    fun size(L) = 
      if L = nil then 0
      else 1 + size(tl(L))

    (* Another helper function that either returns SOME type or NONE *)
    
    fun  tchelper(IntExpr(a) , vts ) = SI

    | tchelper(SuccExpr(e1), vts) = if tchelper(e1, vts) = SI then SI else NONE

    | tchelper(PredExpr(e2), vts) = if tchelper(e2, vts) = SI then SI else NONE

    | tchelper(FunExpr(a ,b,c,d,e'), vts) = 
      if tchelper(e', (a, Arrow(c,d)) :: (b,c)::vts) = SOME (d)  
      then SOME(Arrow(c,d))
      else NONE
      
    | tchelper(VarExpr(c) , vts ) = vt( SOME c, vts)

    | tchelper(ApplyExpr(e1,e2), vts) = 
      ( fn (SOME(Arrow(c,d)) , et) => if SOME c = et then SOME d else NONE | (_,_) => NONE ) (tchelper(e1,vts) , tchelper(e2, vts))

    | tchelper(BeqExpr(a,b,c,d), vts) = if tchelper(a,vts) = tchelper(b, vts)   then tchelper(c,vts) else tchelper(d, vts)

    | tchelper(TupleExpr(x :: xs), vts) = if size(x::xs) >= 2
        then (fn x::xs=>x) (foldr (fn(v,s)=> tchelper(v,vts)::s) [] (x::xs)) else NONE
            
    | tchelper(LetExpr(L : string list, e1, e2) , vts) = 
    if tchelper(e1, vts) = tchelper(e2, vts) andalso size(L) >= 1
     then 
          tchelper(e2, vts) else tchelper(e1,vts)

    | tchelper(SumExpr(i: int, e: expr, K), vts) = if SOME (hd(K)) = tchelper(e,vts) then SOME (hd K) else tchelper(e,vts) 

    | tchelper(CaseExpr(e,(s1, e1):: xs : (string * expr) list ) ,  vts)=
         foldr (fn ((s1,e1), seed)=>if vt(SOME s1,vts) = tchelper(e,vts) then tchelper(e1,vts) else seed) (tchelper(e,vts)) ((s1,e1)::xs)
              
  in
    tchelper(e, Varst)
  end;


(* This function takes an expression and evaluates it *)

fun eval( ex : expr) = 
  let


    (* This function just obtains the string from an option *)

    fun getstr(s:string option) = 
        let 
          val i = s 
        in 
          case i of
                        SOME(a) => a 
            |NONE => "" 
        end

        (* Implementing the substitute function as a helper for the semantic function *)
    fun sub(e as IntExpr(_)) _ _ = e
    | sub(SuccExpr(e1)) s r = SuccExpr(sub e1 s r)   
    | sub(PredExpr(e1)) s r = PredExpr(sub e1 s r)
    | sub(FunExpr(a,b,c,d,e)) s r = 

        if SOME s = a orelse SOME s = b 
        then FunExpr(a,b,c,d,e)
        else FunExpr(a,b,c,d, sub e s r)

    | sub(e as VarExpr(c)) s r = if c = s then r else e
    | sub(ApplyExpr(e1,e2)) s r = ApplyExpr((sub e1 s r),(sub e2 s r))
    | sub(BeqExpr(a,b,c,d)) s r = BeqExpr((sub a s r),(sub b s r),(sub c s r),(sub d s r))
    | sub(TupleExpr(x::xs)) s r = TupleExpr((sub x s r):: sub (hd(xs)) s r :: [])     
    | sub(LetExpr(L : string list , e1, e2)) s r = LetExpr(L, sub e1 s r , sub e2 s r)
    | sub(SumExpr(i:int, e: expr, L : typ list)) s r = SumExpr(i, sub e s r ,L )
    | sub(CaseExpr(e,(s1, e1):: xs : (string * expr) list)) s r = CaseExpr(sub e s r, (s1, sub e1 s r)::xs)


    (* The sem function takes an expression and evaluates the dynamic semantics for the expression *)

    fun sem (e as IntExpr(_)) = (e)
    | sem (e as SuccExpr(_)) = (e)
    | sem (e as PredExpr(_)) = (e)
    | sem (e as FunExpr(_,_,_,_,_)) = (e)
    | sem (e as VarExpr(_)) = (e)
    | sem (e as ApplyExpr(e1 as FunExpr(a,b,c,d,e'), e2: expr)) =
        (fn(v1)=> sem (sub (sub e' (getstr(b)) v1) (getstr(a)) e1)) (sem e2)
                
    | sem (e as BeqExpr(a,b,c,d)) =  
      (fn(v) => if v = b then c else d) ( sem a) 

    | sem(e as TupleExpr(x::xs)) = sem x
    | sem(e as LetExpr(L: string list, e1,e2)) = sem ( sub (e1) (hd(L)) e2)
    | sem(e as SumExpr(i: int, e': expr, K)) = sem(e') 
    | sem(e as CaseExpr(e',(s1, e1):: xs : (string * expr) list)) =
      foldr((fn(z,y) => sem (sem (sub e' z y)))) (e1) ((s1::[])) 
      


    in 
    (fn (e) => e) (sem ex)
    end;

