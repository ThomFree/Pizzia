
# Comment implémenter Pizzia ?
Cette partie va vous décrire une manière d'implémenter notre Pizzia au sein de votre Zia.
## Architecture des modules
Les modules ne sont qu'une partie du Zia. En effet avant que vous puissiez implémenter vos modules, vous allez devoir faire le nécessaire pour ceux-ci.  

Voici un schéma des étapes que traverse une requête :  

<p align="center">
	<img src="https://i.imgur.com/bvjzFcT.png">
</p>

Les modules dans le schéma ci dessus, **sont exécutés dans un ordre bien précis**, ne pas le respecter transformerait la réponse et pourrait la rendre inutilisable. **Vous êtes libre de stocker l'ordre de vos modules comme bon vous semble.**

Comme le schéma ci-dessus le présente, vous allez devoir :
 1. Ouvrir un socket et accepter les connexions entrantes
 2. Lire sur ces sockets les données
	 - A partir de ces données, créer un *IRequest* et mettre les données dans le *IRequest* à l'aide de la fonction ```setRaw() ```
	 - Instancier les modules et les exécuter à la suite (au moins un des modules doit faire un ```setRaw()``` dans une classe *IResponse*)
	 - Terminer les modules
3. Ecrire sur ces sockets les requêtes traitées (en faisant un ```getRaw()``` de la classe *IResponse*

Après la lecture de ce paragraphe vous devriez avoir une bonne vision d'ensemble des modules et de l'architecture du Zia, il est maintenant tant pour vous de plonger dans [les exemples](https://github.com/ThomFree/Pizzia/tree/master/mods).

## Implémentation
1. Télécharger le dossier *api/* du repo pour pouvoir commencer.
2. Implémenter toutes les interfaces de l'API
3. Intégrer Pizzia au sein de votre Zia

Afin de tester votre Zia, nous vous conseillons d'utiliser nos exemples et de comparer le rendu à celui que nous vous fournissons.
# Comment créer son module ?
Pour créer votre module, créer une classe qui hérite de notre classe ```IModule```.

Votre classe doit contenir 2 fonctions membres :

- ```getName()``` qui retourne une string contenant le nom de votre module.
- ```run()``` qui execute le module et qui retourne un ```EModuleStatus```

```run()``` prend 4 arguments qui sont :

- ```IRequest &req``` : Information sur la requete
- ```IResponse &res``` : Information sur la réponse
- ```IMapContainer &config``` : Paramètres unique au site web
- ```IMapContainer &session``` : Paramètres unique au socket


<p align="center">
	<img src="https://i.imgur.com/oH39LSz.png">
</p>

Voici un exemple (défini [ici](https://github.com/ThomFree/Pizzia/tree/master/mods/easy-HelloWorld)) qui permet de renvoyer "Hello World!" lors d'une requete.

# Comment transformer son module en bibliothèque (lib) ?

Tout d'abord il vous suffit de rajouter un extern à la fin la classe de votre module :
<p align="center">
	<img src = "https://i.imgur.com/WawXDq9.png">
</p>

Comme le module `HelloWorld` hérite de `Pizzia::IModule`, vous pouvez stocker vos 
modules à la suite dans un vecteur de `std::unique_ptr<Pizzia::IModule>`.
Vous pouvez ensuite transformer votre module en lib (`.so`).

Ensuite, une fois votre DLWrapper codé, vous pourrez exécuter votre fonction `run()` de votre module via le pointeur retourné par votre entry Point. 
