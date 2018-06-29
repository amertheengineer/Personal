(* 
	Amer Abdelaziz
	U25449742

	This free variable function takes an expression 
	and determines the free variables of th 
	expression and adds it onto a list

	“I pledge my Honor that I have not
	cheated, and will not cheat, on this assignment.”

*)




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


fun fv ex =
       let
       val f_list : string list = [];
       (* These three helper functions are used to dtermine some properties of the list *)

        fun elemof( i:string , str_list:string list) =
               foldr( fn(x,y) => i = x orelse y) false str_list; 


		fun subset(A,B) =
				foldr( fn(x,y) => elemof(x,B))false A;

		fun same( A, B) =
				foldr( fn(x,y) => subset((A),(B)))false A;

		(* This helper function is able to build a list by recusrively calling itself for different expressions 
			All these expressions represent different possibilities we could have for the expression we're 
			attempting to find the free variables of. 
			The base case is a VarExpr(a) since it allows us to cons the string onto the initial list of 
			free variables
			While the FunExpr represents several cases where either the function or the parameter name
			is empty and we deal with different cases for each
			We don't have to care about the types of variables since they don't atribute to the free variables 
			of the function

		*)

        fun BuildExp(e:expr, b_list: string list) =

        case e of

           			IntExpr(a) => []
		       |    SuccExpr(e) => BuildExp(e,b_list) 
		       |    PredExpr(e) => BuildExp(e,b_list) 
		       |    FunExpr(a,b,_,_,e: expr) => 			
		       				let
		       					val x = a 
		       				in
		       					case x of 
		       					SOME x => 
		       						let
		       							val y = b
		       						in
		       							case y of
		       							SOME y => BuildExp(e, x :: y :: b_list )
		       						|	NONE => BuildExp(e, x :: b_list)		
		       						end
		       				|	NONE => 
	       							let
	       								val z = b
	       							in
	       								case z of
	       								SOME z => BuildExp(e, z :: b_list )		
	       							|	NONE => BuildExp(e, b_list)	
	       							end
		       				end				
		       |    ApplyExpr(a,b) =>  BuildExp(a,b_list) @ BuildExp(b,b_list) 
		       |    VarExpr(a) => if(elemof(a,b_list)) then [] else a::f_list
		       |    BeqExpr(a,b,c,d) => if same(BuildExp(a,b_list), BuildExp(b,b_list)) then BuildExp(c,b_list) else  BuildExp(d,b_list)

   	 
   in

     BuildExp(ex, f_list)
   
   end;


(* This function enables us to substitute an expression e for free variable x in exprssion ep ( e prime) 

	We recursively call the sub function as an expression inside the different possible expression for 
	e prime

*)
fun sub (e: expr) (s : string)  (ep: expr)  =

	case ep of

				IntExpr(a) => e
			|	SuccExpr(e1) => SuccExpr( sub e1 s ep )
			|	PredExpr(e2) => PredExpr( sub e2 s ep )
			|	FunExpr(a,b,c,d,e') => 
					let 
						val x = b
						val y = SOME s
					in	
						case x of 
							 SOME y => FunExpr(a,b,c,d,e')
						|	 NONE => FunExpr(a,b,c,d,sub e s e')	
					end 
							
			|	ApplyExpr(e3, e4)=> ApplyExpr(sub e s e3 , sub e s e4)
			|	VarExpr(c)=> if (s = c) then e else VarExpr(c) 
			|	BeqExpr(a,b,c,d) => if sub e s a = sub e s b then sub e s c else sub e s d;
