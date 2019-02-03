# Medium : Request Debugger
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