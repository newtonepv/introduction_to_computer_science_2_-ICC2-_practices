import matplotlib.pyplot as plt

# Função para ler dados do arquivo
def ler_dados(arquivo):
    qtd_itens = []
    tempos = []
    with open(arquivo, 'r') as f:
        for linha in f:
            dados = linha.split()
            qtd_itens.append(int(dados[0]))
            tempos.append(float(dados[1]))
    return qtd_itens, tempos

# Carregar os dados dos arquivos
qtd_forca_bruta, tempo_forca_bruta = ler_dados('/home/edvsimoes/Documentos/GitHub/problema_da_mochila/tempo_forca_bruta.dat')
qtd_greedy, tempo_greedy = ler_dados('/home/edvsimoes/Documentos/GitHub/problema_da_mochila/tempo_greedy.dat')
qtd_programacao_dinamica, tempo_programacao_dinamica = ler_dados('/home/edvsimoes/Documentos/GitHub/problema_da_mochila/tempo_programacao_dinamica.dat')

# Plotar gráficos
plt.figure(figsize=(10, 6))

plt.plot(qtd_forca_bruta, tempo_forca_bruta, label='Força Bruta', marker='o')
plt.plot(qtd_greedy, tempo_greedy, label='Guloso (Greedy)', marker='o')
plt.plot(qtd_programacao_dinamica, tempo_programacao_dinamica, label='Programação Dinâmica', marker='o')

# Adicionar rótulos e título
plt.xlabel('Quantidade de Itens')
plt.ylabel('Tempo de Execução (segundos)')
plt.title('Comparação de Algoritmos - Problema da Mochila')
plt.legend()

# Exibir o gráfico
plt.grid(True)
plt.show()
