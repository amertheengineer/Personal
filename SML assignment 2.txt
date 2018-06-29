(*
 Amer Abdelaziz 
	U25449742
	Assignment 2 SML
	"I pledge my Honor
	that I have not cheated, and will 
	not cheat, on this assignment."
*)

(* The size function uses folr to incerement the value of x for the size of a list)
fun size(a,A) = 
	foldr( fn(_,x) => x+1) 0 A;

(* The elementof function returns true an element a is part of a list B*)
fun elementof(a, (b,B) ) = 
	foldr( fn(x,y) => y orelse (a=x)) false B; 

(* The subset function returns true if the set A is a subset of B )
fun subset((a,A),(b,B)) =
	foldr( fn(x,y) => elementof(x,(b,B)))false A;


(* This function returns true if two sets are true, false otherwise *)
fun same( (a,A),(b,B)) =
	foldr( fn(x,y) => if a = b then subset((a,A),(b,B)) else false)false A;


fun union( (a,A),(b,B))	=
	 foldr( fn(c,Y) => if elementof(c,(b,Y)) = false then c::Y else [] @(Y)) B A;



(* This function unions list A with B and returns the size*)
fun union( (a,A), (b,B))=
	foldr ( fn(c,(b,S)) => if elementof(c,(b,S)) = false then (size(b,S)+ 1, c::S) else (size(b,S), S) ) (b,B) A;

(* This function intersects list A with B and returns the size)
fun intersection( (a,A) , (b,B))=
	foldr( fn(c,(b,S)) => if elementof(c,(b,B)) then (size(b,S)+1,c::S) else(0,S))(0,[]) A;


(* This function unions a list of lists and returns the size )
fun lunion( (a,A)::K )=
	foldr( fn(L,(a,N)) => union(L,(a,N)))(a,A) (K);


(* This function intersects a list of lists and returns the size )
fun lintersection( (a,A)::K)=
	foldr( fn(L,(a,N)) => intersection(L,(a,N))) (a,A) K;


