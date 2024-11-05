import matplotlib.pyplot as plt
from collections import defaultdict

# Nome do arquivo .dat
arquivo = 'exec_temp.dat'

# Dicionário para armazenar os valores agrupados
dados_agrupados = defaultdict(list)

# Lendo os dados do arquivo e agrupando por número de cidades
with open(arquivo, 'r') as f:
    for linha in f:
        dados = linha.split()
        numero_cidade = int(dados[0])
        tempo_execucao = float(dados[1])
        dados_agrupados[numero_cidade].append(tempo_execucao)

# Calculando a média para cada número de cidades
numeros_cidades = []
tempos_execucao_medios = []

for numero_cidade, tempos in dados_agrupados.items():
    media_tempo = sum(tempos) / len(tempos)
    print(str(numero_cidade)+" "+str(media_tempo))
    numeros_cidades.append(numero_cidade)
    tempos_execucao_medios.append(media_tempo)

# Criando o gráfico
plt.figure(figsize=(10, 6))
plt.plot(numeros_cidades, tempos_execucao_medios, marker='o', linestyle='-', color='b')

# Adicionando títulos e rótulos
plt.title('Número de Cidades vs. Tempo Médio de Execução')
plt.xlabel('Número de Cidades')
plt.ylabel('Tempo Médio de Execução (segundos)')
plt.grid(True)

# Mostrando o gráfico
plt.show()
