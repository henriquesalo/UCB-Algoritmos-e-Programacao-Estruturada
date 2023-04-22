reprovados = 0
aprovados = 0
menor_media = 10

for i in range(25):
    media = float(input(f"Digite a media do aluno {i+1}: "))

    if media < 0 or media > 10:
        print("Media invalida. Insira um valor entre 0 e 10.")
        continue

    if media < menor_media:
        menor_media = media

    if media >= 6.9:
        aprovados += 1
    else:
        reprovados += 1

print(f"\nQuantidade de alunos aprovados: {aprovados}")
print(f"Quantidade de alunos reprovados: {reprovados}")
print(f"Menor media informada: {menor_media:.2f}")