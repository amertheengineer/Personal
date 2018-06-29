(* STERLING types *)
datatype typ = Int | Arrow of typ * typ; (* i.e., Arrow(argType, returnType) *)
(* STERLING expressions *)
datatype expr =
 IntExpr of int
| SuccExpr of expr (* computes the successor of the int-type subexpression *)
| PredExpr of expr (* computes the predecessor of the int-type subexpression *)
| FunExpr of string option * string option * typ * typ * expr
 (* i.e.: FunExpr(funName, paramName, paramType, returnType, bodyExpr) *)
| ApplyExpr of expr * expr
 (* i.e.: ApplyExpr(funExpr, argumentExpr) *)
| VarExpr of string
| BeqExpr of expr * expr * expr * expr;
 (* i.e.: BeqExpr(testExpr1, testExpr2, toBranchExpr, elseBranchExpr) *)



(* Amer Abdelaziz
	U25449742	
		
		This program is given an expression and then evaluates it and returns 
		either an expression or a 'stuck' exception or an infinite loop	

		 “I pledge my Honor that I have not
		cheated, and will not cheat, on this assignment.”
*)

use "as3.sml"

(* This type-checker function takes an expressions and determines whether it's well or ill-typed *)

fun tc ( e: expr)=
	let
		(* Using the list data structure to keep track of the functions and their types *)
		val Varst = []
		val SI = SOME Int

		(* Helper function to retrieve the type of the function *)
		fun vt(s: string option , (var ,t) :: Varst) = 
			if s = var then SOME (t) 
			else vt(s,Varst)
		| vt(_,nil) = NONE


		(* Another helper function that either returns SOME type or NONE *)
		
		fun	 tchelper(IntExpr(a) , vts ) = SI

		|	tchelper(SuccExpr(e1), vts) = if tchelper(e1, vts) = SI then SI else NONE

		|	tchelper(PredExpr(e2), vts) = if tchelper(e2, vts) = SI then SI else NONE

		|	tchelper(FunExpr(a ,b,c,d,e'), vts) = 
			if tchelper(e', (a, Arrow(c,d)) :: (b,c)::vts) = SOME (d)  
			then SOME(Arrow(c,d))
			else NONE
			
		|	tchelper(VarExpr(c) , vts ) = vt( SOME c, vts)

		|	tchelper(ApplyExpr(e1,e2), vts) = 
			( fn (SOME(Arrow(c,d)) , et) => if SOME c = et then SOME d else NONE | (_,_) => NONE ) (tchelper(e1,vts) , tchelper(e2, vts))
		|	tchelper(BeqExpr(a,b,c,d), vts) = if tchelper(a,vts) = tchelper(b, vts)		then tchelper(c,vts) else tchelper(d, vts)
	in
		tchelper(e, Varst)
	end;




exception stuck;

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

		(* The sem function takes an expression and evaluates the dynamic semantics for the expression *)

		fun sem (e as IntExpr(_)) = (e)
		|	sem (e as SuccExpr(_)) = (e)
		|	sem (e as PredExpr(_)) = (e)
		|	sem (e as FunExpr(_,_,_,_,_)) = (e)
		|	sem (e as VarExpr(_)) = (e)
		|	sem (e as ApplyExpr(e1 as FunExpr(a,b,c,d,e'), e2: expr)) =
				(fn(v1)=> sem (sub (sub e' (getstr(b)) v1) (getstr(a)) e1)) (sem e2)
								
		|	sem (e as BeqExpr(a,b,c,d)) =  
			(fn(v) => if v = b then sem c else sem d) ( sem a) 
			
		|	sem (e as _) = raise stuck 


		in 
		(fn (e) => e) (sem ex)
		end;
