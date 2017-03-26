#!/usr/bin/env python3
from lxml import html, etree
import requests


# Converte os números hexadecimais em texto, limitando para todos que tem tamanho 2 para limitar que entre lixo
# É usando a posição 2 da lista, pois é onde se encontra os números
def convertHex(line):
	return bytearray.fromhex(' '.join(word for word in line[2].split() if len(word) == 2)).decode()

# função que retorna o comentário da página html como uma string
def getComment(tree):
	return str(tree.xpath('//comment()'))

def main():
   url = 'http://desafio-paradigmas.appspot.com'
   page = requests.get(url)
   print(page.text)
   tree = html.fromstring(page.content)
   content = tree.xpath("//p")
   print(content[0].xpath('text()')[0])
   print(convertHex(getComment(tree).split("\n")))  # converte a string obtida em getComment em uma lista dividida pelos "\n" (quebra de texto)

if __name__ == '__main__':
   main()


#   tree.xpath('//comment()')
#   str(string)
#   str.split("\n")
#   l[2]

