def main():
    largura = float(input("Qual a largura da parede?"))
    altura = float(input("Qual a altura da parede?"))
    area_pintada = largura * altura
    total_tinta = (area_pintada * 300) / 2000.0
    print(f"Foram usadas {total_tinta} de latas.")
    

if __name__ == "__main__":
    main()