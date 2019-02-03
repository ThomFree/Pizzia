# [EN] Medium : Request Debugger
## Description
The purpose of this example is to show you how to make a **basic request debugger**. It will simply display on a html page everything the server received.
This example uses 3 modules :
- RequestParserModule : Parse everything that is in the ```getRaw()``` of the ```IRequest```. It parses : URI parameters, HTTP headers, HTTP method, HTTP version, URI and the body.
- RequestDebuggerModule : This module make a body wich contains all the debug and html data.
- ResponseMakerModule : This is the final module that convert everything in ```IResponse``` and call the ```setRaw()``` method.
## Pipeline
The pipeline is not very complicated, but it is crucial that every module is called one after another.
<p align="center">
  <img src="https://i.imgur.com/4wqj5zx.png">
</p>

## Expected result
If you have done everything right you should see in your browser :
<p align="center">
  <img src="https://i.imgur.com/S8Wkbqa.png">
</p>
And with URI parameters :
<p align="center">
  <img src="https://i.imgur.com/n5AihdG.png">
</p>

# [FR] Intermédiaire: Request Debugger
## Description
Le but de cet exemple et de vous montrer **un débogueur de requête HTTP très basique**. Cet exemple retourne une page HTML qui contient toutes les données reçues dans la requête.
Cet exemple utilise trois modules :
- RequestParserModule : Traite toutes les données qui se trouvent dans ```getRaw()``` de ```IRequest```. Il traite l'URI, les paramètres URI, les en-têtes HTTP, la méthode HTTP ainsi que la version et le contenu de la page (body).
- RequestDebuggerModule : Ce module fabrique un contenu de page contenant toutes les données de la requête.
- ResponseMakerModule : C'est le module finale, il convertit tout le contenu de ```IResponse``` en chaîne de caractère et appelle la méthode ```setRaw()```.
## Pipeline
La pipeline est vraiment simple mais cruciale : chaque module doit être appelé l'un après l'autre.
<p align="center">
  <img src="https://i.imgur.com/4wqj5zx.png">
</p>

## Résultat attendu
Si vous avez tout terminé, vous devriez apercevoir dans votre navigateur :
<p align="center">
  <img src="https://i.imgur.com/S8Wkbqa.png">
</p>
Et avec des paramètres URI :
<p align="center">
  <img src="https://i.imgur.com/n5AihdG.png">
</p>