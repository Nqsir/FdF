# FdF
Ce projet consiste à créer graphiquement la représentation schématique d’un terrain en relief

Usage :

    • ./fdf fichierfdf.fdf
    • touche de déplacement :

      w : Avant,
      s : Arrière,
      a : Gauche,
      d : Droite,
      r : Refresh,
      esc : Quit,
      Flèche haut : Augmentation hauteur,
      Flèche bas : Diminution hauteur,
      + : Augmentation zoom,
      - : Diminution zoom.

Principales notions :

    • Algorithme de tracé de segment de Bresenham,
    • Première utilisation d'une bibliothèque graphique,
    •  Initiation à la programmation dite “evenementielle”.

Résumé du sujet :

La représentation en relief d’un terrain est une pratique clef de la cartographie moderne.
Par exemple, en cette ère d’exploration spatiale, avoir une reproduction en trois
dimensions de la surface de Mars est un prérequis indispensable à la conquête de cette
planète. Autre exemple, comparer des représentations en trois dimensions d’une zone ou
l’activité tectonique est importante permet de mieux comprendre ces phénomènes et leur
évolution, permettant ainsi d’être mieux préparés.

Ce projet consiste à créer graphiquement la representation schématique (en “fils de
fer” ou “wireframe” en anglais) d’un terrain en relief en reliant différents points (x, y,
z) par des segments. Les coordonnées du terrain seront stockées dans un fichier passé en
paramètre, dont voici un exemple :

$>cat 42.fdf

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\
0 0 10 10 0 0 10 10 0 0 0 10 10 10 10 10 0 0 0\
0 0 10 10 0 0 10 10 0 0 0 0 0 0 0 10 10 0 0\
0 0 10 10 0 0 10 10 0 0 0 0 0 0 0 10 10 0 0\
0 0 10 10 10 10 10 10 0 0 0 0 10 10 10 10 0 0 0\
0 0 0 10 10 10 10 10 0 0 0 10 10 0 0 0 0 0 0\
0 0 0 0 0 0 10 10 0 0 0 10 10 0 0 0 0 0 0\
0 0 0 0 0 0 10 10 0 0 0 10 10 10 10 10 10 0 0\
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

Chaque nombre correspond à un point dans l’espace :\
• La position horizontale correspond à son abscisse.\
• La position verticale correspond à son ordonnée.\
• La valeur correspond à son altitude.
