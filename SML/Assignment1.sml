
(* Amer Abdelaziz 
	U25449742
	Assignment 1 SML
	"I pledge my Honor
	that I have not cheated, and will 
	not cheat, on this assignment."
*)
(* Size of list function*)

fun size( a: int, L : int list)=
if null L then 0
else 1 + size(a,tl(L));


(* elementof function returns true if an element is oart of a list*)
fun elementof(a, (n,nil))= false
| elementof(a, (n,L))=
	if(a = hd(L)) then true	
		else elementof(a, (n,tl(L)));
	
	
(*subset function returns true if a list is a part of another list*)
fun subset( (a,[]),(n,K)) = true
| subset( (a,L),(n,K)) =  if elementof( hd(L), (n,K)) 
		then subset( ((a-1),(tl(L))), (n,K))
			else false;

(*This function returns true if two lists are the same, false otherwise*)	
fun same( (n,[]) , (a,K)) = false
| same( (n,L) , (a,K)) = if( n =a) 
	then subset( (n,L), (a,K))
		else false;
	
(*This function returns a list that combines the two given lists, no repition*)
fun union( (n,[]) , (a,K)) = K
| union( (n,L) , (a,K)) =
	if elementof(hd(L) , (K)) then union( (n,tl(L)) , (a,K))
		else hd(L)::union( (n,(L)) , (a,K));
	

	(* This function returns the union of two sets*) 	
fun lunion( [(a,A), (b,Y), (c,[])]) = union( (a,A),(b,Y))
 | lunion( [(a,A),(b,Y),(c,Z)])=
	if elementof( hd(Z), (b,Y)) then lunion( [(a,A),(b,Y),(c,tl(Z))])
	  else hd(Z):: union((a,A),(b,Y));

(* This function returns an intersected list from two lists*)	  
fun intersect( (a,[]),(b,Y)) = []
| intersect( (a,A),(b,Y))=
	if elementof( hd(A), (b,Y)) then hd(A):: intersect((a,tl(A)),(b,Y))
		else intersect((a,tl(A)),(b,Y));


(* This function returns the intersection of every set in a list of sets*)
fun lintersection([ (a,A),(b,Y),(c,[])]) = intersect((a,A),(b,Y))
 | lintersection([(a,A),(b,Y),(c,Z)])= if elementof(hd(Z), (b,Y))
	then lintersection([(a,A),(b,Y),(c,tl(Z))])
		else hd(Z):: lintersection([(a,A),(b,Y),(c,tl(Z))]);


(* This function takes a set of integers and returns a list of subsets*)
fun powerset([], L) = [L]
| powerset(x::xs,L)=
	powerset(xs,L) @ powerset(xs, x::L);

  

