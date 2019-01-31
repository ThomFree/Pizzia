# Pizzia
The Zia API for hungry developers :pizza:
<center><img src="https://i.imgur.com/kIxNCUr.png"/></center>

## Introduction
Pizzia is an **API** for the **Epitech Zia** project proposed for **Paris**. Pizzia permits to make **Zia modules** in elegant way using a **high-level abstraction** of the HTTP protocol.

The **core idea** of the API is that modules should be considered as **pieces of puzzles**: they join one by one to give **a chain of modules** that will then be executed by the web server: it's also called a **pipeline** !

The web server will act as **a mediator** (look at [mediator design pattern](https://en.wikipedia.org/wiki/Mediator_pattern)) with its modules, it will run them **one by one** (in order of priority) by mutually passing them the following parameters:

- **the request** as an object that implement the `Pizzia::IRequest` that hold all request data
- **the request** as an object that implement the `Pizzia::IResponse` that hold all future response data
- **the configuration** as an object that implement`Pizzia::IMapContainer` that hold a key value wrapper of the configuration data
- **the session** as an object that implement`Pizzia::IMapContainer` that hold a key value wrapper of persistant data accross modules (also called session data)

### A word about the map container:
*TODO*


## Quick start
We have set up a tutorial (in french) to understand Pizzia and start quickly on our API: you will find it [here](https://thomfree.github.io/Pizzia/start.html).



