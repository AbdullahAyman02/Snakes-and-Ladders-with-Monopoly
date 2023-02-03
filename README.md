# Snakes-and-Ladders-with-Monopoly

<div align="left"><img src="/media/Dice.gif" alt="Dice"></div>
<div align="center"><img src="/media/title.jpg" alt="Title"></div>
<div align="right"><img src="/media/Dice.gif" alt="Dice"></div>

## Table of Contents

* [Project Description](#Project-Description)
* [Gameplay](#Gameplay)
* [Notes](#Notes)
* [References](#References)

# Project Description

This game is a mixture of the two very popular games, Snakes & Ladders and Monoply. There are two modes in the game: Design mode is where the user is able to build the playing grid and Play mode is where the players can play against each other. Four players move in a grid using snakes, ladders, and cards as the game's basic concept. The players land on special cells (cards) that can either be good or bad. The goal of the player is to be the first person to reach the final cell.

## Cards:
<div>
    <table>
        <tr style="font-size:30px;">
            <th>Cards</th>
            <th>Description</th>
        </tr>
        <tr>
            <td>Card 1</td>
            <td>Decrements the value of the passing player’s wallet by a value specified when creating the grid.</td>
        </tr>
        <tr>
            <td>Card 2</td>
            <td>Moves the player forward to the start of the next ladder in the grid. If no ladders ahead, do nothing.</td>
        </tr>
        <tr>
            <td>Card 3</td>
            <td>Gives the player an extra dice roll.</td>
        </tr>
        <tr>
            <td>Card 4</td>
            <td>Prevents the player from rolling the next turn. </td>
        </tr>
        <tr>
            <td>Card 5</td>
            <td>Moves the player backward with the same number of steps that he just rolled. If he reaches a ladder, a snake, or a card at the end of moving, take it.</td>
        </tr>
        <tr>
            <td>Card 6</td>
            <td>Instructs the player to go to a specific cell. If the destination cell contains a ladder, snake, or card, take it.</td>
        </tr>
        <tr>
            <td>Card 7</td>
            <td>Restarts the game for the first player whose cell is after the current player in the grid. Restarting the game for a player makes him go to cell number 1.</td>
        </tr>
        <tr>
            <td>Card 8</td>
            <td>This card is a prison. When a player stops at a Card8 cell, the player should choose either to pay specific amount of coins to go out of the prison, or stay in prison and not playing for 3 turns.</td>
        </tr>
        <tr>
            <td>Card 9</td>
            <td>Gives the player the option to buy this cell and all cells containing a card with the same number. For example, if a player chooses to buy a cell with Card10, he will own all cells having a Card10.</td>
        </tr>
        <tr>
            <td>Card 10</td>
            <td>Same as card 9</td>
        </tr>
        <tr>
            <td>Card 11</td>
            <td>Same as card 9</td>
        </tr>
        <tr>
            <td>Card 12</td>
            <td>This card moves the ownership of the most expensive station that the current user owns from the current user to the player that has the least amount of coins in his wallet.</td>
        </tr>
    </table>
</div>

## Design Mode Description:
<table>
    <tr style="font-size:30px;">
        <th>Image</th>
        <th>Description</th>
    </tr>
    <tr>
        <td><img src="/images/Menu_Ladder.jpg" alt = "Ladder"></td>
        <td>Adds a ladder by specifying its start and end cells</td>
    </tr>
    <tr>
        <td><img src="/images/Menu_Snake.jpg" alt = "Snake"></td>
        <td>Adds a snake by specifying its start and end cells</td>
    </tr>
    <tr>
        <td><img src="/images/Menu_Card.jpg" alt = "Card"></td>
        <td>Adds one of the 12 cards to make this a special cell</td>
    </tr>
    <tr>
        <td><img src="/images/Menu_Copy_Card.jpg" alt = "Copy"></td>
        <td>Copy a card with all its data to the clipboard</td>
    </tr>
    <tr>
        <td><img src="/images/Menu_Cut_Card.jpg" alt = "Cut"></td>
        <td>Cuts a card with all its data to the clipboard</td>
    </tr>
    <tr>
        <td><img src="/images/Menu_Paste_Card.jpg" alt = "Paste"></td>
        <td>Paste the card in the clipboard to the destination cell</td>
    </tr>
    <tr>
        <td><img src="/images/Menu_Delete.jpg"v alt = "Delete"></td>
        <td>Deletes the game object in the cell that the user chooses</td>
    </tr>
    <tr>
        <td><img src="/images/Menu_Save.jpg" alt = "Save"></td>
        <td>Save all the game objects of the grid to a file</td>
    </tr>
    <tr>
        <td><img src="/images/Menu_Load.jpg" alt = "Load Grid"></td>
        <td>Open a saved grid from a file and re-draw it</td>
    </tr>
    <tr>
        <td><img src="/images/Menu_SwitchToGame.jpg" alt = "Switch to game"></td>
        <td>Switch to play mode any time even before saving</td>
    </tr>
    <tr>
        <td><img src="/images/Menu_Exit.jpg" alt = "Exit"></td>
        <td>Exit the application</td>
    </tr>
</table> 

## Play Mode Description
<table>
    <tr style="font-size:30px;">
        <th>Image</th>
        <th>Description</th>
    </tr>
    <tr>
        <td><img src="/images/Menu_Dice.jpg" alt = "Roll Dice"></td>
        <td>Rolls the dice and performs necessary actions</td>
    </tr>
    <tr>
        <td><img src="/images/Menu_Input_Value.jpg" alt = "Input Value"></td>
        <td>Asks the user to insert a value instead of randomly rolling the dice</td>
    </tr>
    <tr>
        <td><img src="/images/Menu_New.jpg" alt = "New Game"></td>
        <td>Restarts players' positions, wallets, and turn returns to player 0</td>
    </tr>
    <tr>
        <td><img src="/images/Menu_SwitchToGrid.jpg" alt = "Switch to Design Mode"></td>
        <td>Switch to design mode</td>
    </tr>
    <tr>
        <td><img src="/images/Menu_Exit.jpg" alt = "Exit"></td>
        <td>Exit the Application</td>
    </tr>
</table>

# Gameplay

- To launch the game, run 'PT Project.exe'

### Game 1

<div align="center"><img src="/media/Design Mode.gif" alt="Design Mode" width="700px"></div>

### Game 2

<div align="center"><img src="/media/Play Mode.gif" alt="Play Mode" width="700px"></div>

# Notes

- In the rare event of a bug occuring, it may be caused by latency in connection so just reload the game.

# References

Project Document: [MP_Project_DescriptionA_Fall_2022.pdf](https://github.com/MahmoudSamy1452/Assembly-chess-game/files/10551974/MP_Project_DescriptionA_Fall_2022.pdf)


