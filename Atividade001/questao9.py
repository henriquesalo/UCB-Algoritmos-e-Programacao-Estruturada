def main():
    nota1 = float(input("Digite a primeira nota do aluno:"))
    nota2 = float(input("Digite a segunda nota do aluno:"))
    nota3 = float(input("Digite a terceira nota do aluno:"))
    media = ((nota1 * 2) + (nota2 * 3) + (nota3 * 5)) / 10.0
    print(f"Média final do aluno igual à: {media: .2f}")

if __name__ == "__main__":
    main()