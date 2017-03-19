#1. Defina uma função somaQuad(x,y) que calcule a soma dos quadrados de dois números x e y.
def somaQuad(x,y):
	return x**2+y**2

#2. Crie uma função hasEqHeads(l1,l2) que verifique se as listas l1 e l2 possuem o mesmo primeiro elemento.
def hasEqHeads(l1,l2):
	return l1[0] == l2 [0]

#3. Escreva uma função que receba uma lista de nomes e retorne uma lista com a string "Sr. " adicionada 
#   ao início de cada nome. Defina uma função auxiliar para ajudar neste exercício.
def auxSr(l):
	return "Sr. "+l
def addSr(l1):
	return list(map(auxSr, l1))

#4. Crie uma função que receba uma string e retorne o número de espaços nela contidos. Defina uma função auxiliar para ajudar neste exercício.
def auxSpc(s):
	return s == " "
def countSpc(string):
	return len(list(filter(auxSpc,string)))

#5. Escreva uma função que, dada uma lista de números, calcule 3n*2 + 2/n + 1 para cada número n da lista. 
#   Defina uma função auxiliar para ajudar neste exercício.
def auxCalc(n):
	return 3*n**2+2/n+1
def listCalc(l):
	return list(map(auxCalc,l))

#6. Escreva uma função que, dada uma lista de números, retorne uma lista com apenas os que forem negativos. 
#   Defina uma função auxiliar para ajudar neste exercício.
def auxNeg(n):
	return n < 0
def listNeg(l):
	return list(filter(auxNeg,l))

#7. Escreva uma função que receba uma lista de números e retorne somente os que estiverem entre 1 e 100, inclusive. 
#   Defina uma função auxiliar para ajudar neste exercício.
def auxNum(n):
	return n >= 1 and n<=100
def listNum(l):
	return list(filter(auxNum,l))

#8. Escreva uma função que receba uma lista de números e retorne somente aqueles que forem pares. 
#   Defina uma função auxiliar para ajudar neste exercício.
def auxIsEven(x):
	return x%2 == 0
def isEven(l):
	return list(filter(auxIsEven,l))

#9. Crie uma função charFound(c,s) que verifique se o caracter c está contido na string. O resultado deve ser True ou False. 
#   Você não deve usar o operador in. Defina uma função auxiliar para ajudar neste exercício.
def auxChar(c,s):
	return s.find(c)>=0

def charFound(c,s):
	return auxChar(c,s)

#10. Escreva uma função que receba uma lista de strings e retorne uma nova lista com adição de marcações HTML (p.ex.: <B> e </B>) 
#    antes e depois de cada string.
def auxHtml(s):
	return "<i>"+s+"</i>"
def addHtml(l1):
	return list(map(auxHtml, l1))


