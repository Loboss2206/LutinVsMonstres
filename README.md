# 👹 Lutin vs Monstres

Ce travail a été réalisé dans le cadre du projet SAE101 pendant mon semestre 1 de BUT Informatique. Ce projet est un jeu simple où un lutin doit atteindre la sortie tout en évitant les monstres sur une grille. Le jeu est implémenté en C et utilise des fichiers texte pour définir la configuration de la grille et les mouvements du lutin.

## ⚙️ Configuration

Le jeu utilise des fichiers texte pour définir la grille, les monstres et les mouvements du lutin, ainsi :

- Les fichiers grille*.txt définit la structure de la grille et la position des monstres ainsi que leurs modalités de deplacement.
- Les fichiers deplacementsLutin_grille*.txt définit les mouvements du lutin.

## 🛠️ Exécution du jeu

### Option 1 : Vous souhaitez utiliser le fichier executable dejà prêt

1. Clonez ce référentiel sur votre machine locale.

```shell
git clone https://github.com/Loboss2206/LutinVsMonstres.git
```

2. Placez-vous dans ce repertoire en executant cette commande dans votre terminal :

```shell
cd LutinVsMonstres
```

3. Exécutez le jeu en utilisant cette commande dans votre terminal :

```shell
./main
```

### Option 2 : Vous souhaitez créer votre propre fichier executable

1. Assurez-vous que vous avez un compilateur C tel que GCC installé.
2. Clonez ce référentiel sur votre machine locale en faisant cette commande :

```shell
git clone https://github.com/Loboss2206/LutinVsMonstres.git
```

3. Placez-vous dans ce repertoire en executant cette commande dans votre terminal :

```shell
cd LutinVsMonstres
```

4. Compilez le code en exécutant la commande

```shell
gcc *.c -o main
```

5. Exécutez le jeu en utilisant cette commande dans votre terminal :

```shell
./main
```

## 💻 Instructions de jeu

1. Changez les configurations de la grille en changeant les fichiers utilisés si vous souhaitez personnaliser la partie.
2. Lancez la partie
3. Appuyez sur Entrée pour avancer dans la partie
4. Le jeu affichera si vous avez gagné ou perdu à la fin.

## 📋 Auteurs

    Logan Brunet
    Mateus Lopes
    Simon Rigal
    Mathieu Da Vinha

## ⚖️ Licence

Ce projet est sous licence MIT. Pour plus de détails, consultez le fichier LICENSE.

## ✏️ Comment contribuer ?

Si vous êtes enthousiasmé par ce projet et souhaitez contribuer, veuillez consulter le [guide de contribution](https://github.com/Loboss2206/LutinVsMonstres/blob/main/CONTRIBUTING.md) pour plus d'informations.
