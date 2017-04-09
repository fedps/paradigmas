%0 = dom, 1 = seg, 2 = ter, 3 = qua, 4 = qui, 5 = sex, 6 = sab


materia(X,Y,L) :- nextto(X,Y,L); nextto(Y,X,L).

sol(L) :- A = [mat,fis,quim,artes,mus,his,geo],
	     permutation(A,L),
	     materia(mat,mus,L),
             (materia(fis,artes,L);
             materia(fis,his,L)),
             not(materia(geo,quim,L)),
             nth0(1,L,quim).

% A- 
%?- sol([mat,mus,fis,his,geo,artes,quim]).
%false.

% B-
%?- sol([fis,artes,mat,mus,quim,his,geo]).
%false.

% C-
%?- sol([mus,quim,mat,geo,artes,fis,his]).
%false.

% D-
%?- sol([his,quim,fis,artes,geo,mat,mus]).
%true .

% E-
%?- sol([his,quim,geo,artes,fis,mat,mus]).
%false.





