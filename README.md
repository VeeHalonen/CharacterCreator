# CharacterCreator

The program is a prototype character builder (or character creator) for a simple roleplaying game. It allows the user to create simple character sheets that include their character's name, race, gender, class, and allocate 20 points between four stats: strength, agility, intellect, and charisma. It also has random character creation.

As of right now, character sheets only exist inside the program's run and cannot be loaded from or saved into a file. All data will disappear once the program ends.

After opening the program, the user can choose from five options:

<b>New Character</b> allows the user to create a custom character. First, the user is asked for a name for the character. The program also prints a few example names that are randomly generated using the formula: ANY-vowel-consonant-vowel-any. The final letter has a 50% chance to be a vowel or a consonant. Leaving the field empty and pressing enter prints out more example names. There is no input validation here. Next, the user is prompted to choose a race from a few default options or write in their own. Class is chosen similarly. The character’s gender can be chosen from three options: male, female, or genderless. Next, the user can set the character’s stats point by point. They can also at any point choose to allocate the remaining points automatically to random stats.

<b>Random New Character</b> automatically creates a new random character. Race, class, and gender are chosen from the default options, and character names are generated using the same formula as the examples in the custom character creation. Stat points are allocated randomly regardless of class.

<b>Show Characters</b> prints a list of all the characters created during the session in the order of their creation.

<b>Delete</b> allows the user to delete a previously created character from the list. To speed up the process of deleting multiple characters, there is no confirmation dialogue.

<b>Quit</b> exits the program.
