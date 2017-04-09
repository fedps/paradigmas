/*
	Problema: Estudo diário (http://olimpiada.ic.unicamp.br/extras/provas/ProvaOBI2016_f2i1.pdf)
	Bia decidiu que na semana que vem vai estudar todas as noites, iniciando no domingo e terminando no sábado.
	Ela quer fazer a programação do que estudar em cada um dos dias, entre matemática, física, química, artes,
	música, história e geografia, obedecendo às seguintes restrições:
	- Ela deve estudar matemática ou na noite anterior ou na noite seguinte em que ela estudar música.
	- Ela deve estudar física ou na noite anterior ou na noite seguinte em que ela estudar ou artes ou história.
	- Ela não pode estudar geografia na noite anterior ou na noite seguinte em que ela estudar química.
	- Ela deve estudar química na segunda-feira.
*/

%dom = 0, seg = 1, ter = 2, qua = 3, qui = 4, sex = 5, sab = 6

materia(X,Y,L) :- nextto(X,Y,L); nextto(Y,X,L).

sol(L) :- A = [mat,fis,quim,artes,mus,his,geo],
	     permutation(A,L),
	     materia(mat,mus,L),
             (materia(fis,artes,L);
             materia(fis,his,L)),
             not(materia(geo,quim,L)),
             nth0(1,L,quim).

/*
	Questão 19.
	Qual  das  seguintes  alternativas  é  uma
	sequência de matérias, de domingo até sábado?
	(A) Matemática, música, física, história, geografia,
	    artes, química
	(B) Física, artes, matemática, música, química, his-
	    tória, geografia
	(C) Música, química, matemática, geografia, artes,
	    física, história
	(D) História, química, física, artes, geografia, ma-
	    temática, música
	(E) História, química, geografia, artes, física, ma-
	    temática, música
*/

/*
?- sol([mat,mus,fis,his,geo,artes,quim]).
?- sol([fis,artes,mat,mus,quim,his,geo]).
?- sol([mus,quim,mat,geo,artes,fis,his]).
?- sol([his,quim,fis,artes,geo,mat,mus]).
?- sol([his,quim,geo,artes,fis,mat,mus]).
*/
