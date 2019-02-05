# Pizzia
The Zia API for hungry developers :pizza:

## [🇫🇷 French documentation and Github Page](https://thomfree.github.io/Pizzia/)

## [👑 Why vote for Pizzia during the elections ?](https://thomfree.github.io/Pizzia/faq.html)

<center><img src="https://i.imgur.com/kIxNCUr.png"/></center>

## Introduction
Pizzia is an **API** for the **Epitech Zia** project proposed for **Paris**. Pizzia allow you to make **Zia modules** in an elegant way using a **high-level abstraction** of the HTTP protocol.

The **core idea** of the API is that modules should be considered as **pieces of a puzzle**: they join one by one to produce **a chain of modules** that will then be executed by the web server: you could also call it a **pipeline**!

The web server will act as **a mediator** with its modules (take a look at the [mediator design pattern](https://en.wikipedia.org/wiki/Mediator_pattern)), it will run them **one by one** (in order of priority) by mutually passing them the following parameters:

- **The request** as an object that implements the `Pizzia::IRequest` which holds all the request data.
- **The request** as an object that implements the `Pizzia::IResponse` which holds all future response data.
- **The configuration** as an object that implements `Pizzia::IMapContainer` which holds a key value wrapper of the configuration data.
- **The session** as an object that implements `Pizzia::IMapContainer` which holds a key value wrapper of persistant data accross modules (also called session data).

**For any details on the ```Pizzia``` interfaces and enumerations, please read :** [the Doxygen](https://thomfree.github.io/Pizzia/doxygen/namespacePizzia.html).


## How to get started ?
We have set up a tutorial (in french) to understand Pizzia and quickly start working on our API: you will find it [here](https://thomfree.github.io/Pizzia/start.html).
