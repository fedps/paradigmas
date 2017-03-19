#1. Escreva uma função que receba uma lista de nomes e retorne uma lista com a string "Sr. " adicionada ao início de cada nome.
def addSr(l1):
	return list(map(lambda l: "Sr. "+l, l1))

#2. Escreva uma função que, dada uma lista de números, calcule 3n*2 + 2/n + 1 para cada número n da lista.
def listCalc(l):
	return list(map(lambda n:3*n*2+2/n+1 ,l))

#3. Crie uma função que receba uma lista de nomes e retorne outra lista com somente aqueles nomes que terminarem com a letra 'a'.
def endA(l):
	return list(filter(lambda l1:'a'==l1[-1],l))

#4. Escreva uma função que, dada uma lista de idades de pessoas no ano atual, retorne uma lista somente com as idades de quem nasceu depois de 1970. 
#   Para testar a condição, sua função deverá subtrair a idade do ano atual. Exemplo de uso:
#   
#   >>> idades([20,30,51,57])
#       [20, 30]
def year70(l):
	return list (filter(lambda l1: 2016-l1 >1970,l))

#5. O código abaixo é escrito em Python imperativo. Escreva um código equivalente usando programação funcional.
#
#   numbers = [1, 2, 3, 4]
#   new_numbers = []
#   for number in numbers:
#   new_numbers.append(number * 2)
#   print(new_numbers)
def doubleNum():
	return list(map(lambda l:l*2,[1,2,3,4]))

