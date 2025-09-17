## Présentation du projet
J'ai développé un jeu en ligne de commande avec des instructions et des actions assez simples. Le but de ce TP était surtout de prendre en main le langage C++.<br>
Ayant pratiqué de nombreux autres langages de programmation, notamment Java et Python, j'ai eu l'occasion d'ajouter le C++ à ma palette, qui était inédit pour moi.
<br> Je présenterai la structure de mon projet, justifierai certains choix et ferai un petit rapport d'étonnement.

## Structure du projet
J'ai opté pour une structure de projet relativement simple. J'ai un dossier `src` qui contient tous les fichiers `.cpp` et un dossier `header` qui contient tous les fichiers `.hpp`.<br>
Mon but était de séparer un minimum les fichiers. Mon principal objectif était d'expérimenter les différences entre le C++ et Java et d'identifier les points d'attention.

## Fichiers principaux
- `main` : C'est le point d'entrée de mon programme. Il contient la fonction `main` qui initialise le jeu et lance la boucle principale.
- `Pokemon` : Ce fichier contient la définition de la classe `Pokemon` qui représente un Pokémon avec ses attributs et ses méthodes.
- `Pokedex` : ici nous avons mis en exergue la notion de singleton. Le pokedex est une entité unique dans le jeu, il n'y a qu'une seule instance de cette classe.
  Pour cela, nous avons utilisé le pattern singleton, qui consiste à avoir un constructeur privé et une méthode statique retournant l'instance unique de la classe.
- `State`: nous avons une classe abstraite `State` qui définit l'interface pour les différents états du jeu. Chaque état hérite de cette classe et implémente ses propres comportements.
- `StateMachine` : Cette classe gère la transition entre les différents états du jeu. Elle contient une pile d'états et permet de changer d'état. Pour cela, nous avons utilisé le pattern state qui permet de changer le comportement d'un objet en fonction de son état. Dans mon cas, j'ai les classes `WelcomeState`, `BattleState`, `ExplorationState` et `GameOverState` qui héritent de la classe `State` pour gérer les différents états du jeu. Elles possèdent deux méthodes `enter` et `update` qui sont appelées dans la boucle principale du jeu.

## Ce que j'ai appris
Cette observation s'appuie davantage sur une comparaison avec Java.
- 'la programmation orientée object': globalement la connait mais en C++, il y a des subtilités par rapport à la manière de défnir les classes, les constructeurs, les destructeurs, l'héritage et le polymorphisme. J'ai appris à utiliser les spécificateurs d'accès (`public`, `private`, `protected`) et à comprendre la différence entre les classes et les structures dans le contexte du C++.
- `La gestion de la mémoire` : En C++, il est crucial de gérer la mémoire manuellement. J'ai appris à utiliser les pointeurs, les références et les allocations dynamiques avec `new` et `delete`. En Java, la gestion de la mémoire est automatique grâce au ramasse-miettes (garbage collector).
- `L'organisation du code` : En C++, il est courant de séparer les déclarations (dans les fichiers `.hpp`) et les définitions (dans les fichiers `.cpp`). Cela m'a aidé à mieux structurer mon code. Cela devait aider à la lecture et à la maintenance du code, mais je n'ai pas eu l'occasion de le tester sur un projet plus vaste.
- `Les templates` : J'ai découvert les templates en C++, qui permettent de créer des classes et des fonctions génériques. C'est une fonctionnalité puissante qui n'existe pas en Java.

## Rapport d'étonnement (lié au C++)
Je trouve qu'en faisant du C++ j'ai une plus grande maîtrise de ce que fait mon programme. En Java, on a tendance à se reposer sur la machine virtuelle pour gérer certains aspects comme la mémoire. En C++, on est plus proche du matériel et on doit être plus vigilant. `De grands pouvoirs impliquent de grandes responsabilités`.<br>
J'ai eu la chance que mon code soit revu par un développeur C++ expérimenté qui m'a donné des conseils précieux pour améliorer mon code sur des facettes où l'attention est moindre en Java comme la copie par valeur et par adresse ou alors la structure typique d'un projet C++.<br>
Malgré tout, bien que chaque structure ait sa place en C++, je trouve que le langage est très verbeux et j'espère que dans les futures années il sera simplifié.
