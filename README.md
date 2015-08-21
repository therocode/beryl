#Beryl - A modular project template instantiator

Beryl is a rough set of a script and modules for instantiating project skeletons with optional parameters. This can be useful if you have a typical way about creating a new project that always involves setting up the same file structure and boilerplate code before you can even get started with project specific things. If you do such, chances are you can turn that into Beryl module.

##Modules

Every Beryl module has at least one of the following:

* A 'files' folder with template files which are copied as-is to the target location
* A python script called 'script' which is called after the copying which can be used to rename files or replace text in files based on parameters passed

##Executing

Beryl is executed as follows:

```
  ./beryl <module_name> <target_directory> [one or several module script specific arguments]
```

Example for the fea_game module which instantiates a template project for the Feather Kit game framework:

```
  ./beryl fea_game . mygame 1920 1080
```

This will instantiate the template for fea_game in the current directory with mygame and 1920 1080 as arguments for the fea_game module (project name and screen resolution).

Modules are placed in the 'modules' directory.
