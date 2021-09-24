#AmmoBox
===================================
1.Appear on the screen 
2.Give ammo to player when collected
-----------------------------------
None

#Animation
==================================
1.Get the next frame required to be 
  animated
2.Know which frame , how fast and 
  if the animation need to be on loop
3.It crop the image based on which 
  part of of the image is needed from 
  the sprite sheet
-----------------------------------
None

#Background
===================================
1.Render the background images 
  based on the gamestate
-----------------------------------
None

#Bullet
===================================
1.Can be shoot by the player
2.Can collide with zombie 
3.can collide with obstacles 
-----------------------------------
Player 

#Cell
===================================
1.Contain all the variables need 
  by a cell
-----------------------------------
None

#CharacterSelection
===================================
1.Is a screen that shows all the 
  characters that can be use by   
  the player 
-----------------------------------
None

#CollisionDetection
===================================
1.Handle all the collisions
-----------------------------------
1.Player
2.Zombie
3.AmmoBox
4.Bullet

#Game
===================================
1.The game controller
-----------------------------------
1.ScreenSize
2.Zombie
3.Background
4.Player
5.AmmoBox
6.CollisionDetection
7.Bullet
8.Obstacle
9.GameState
10.Menu
11.Particles
12.HUD
13.CharacterSelection
14.Grid

#GameState
===================================
1.Is an enum class for all the 
  possible game states
-----------------------------------
None

#Grid
===================================
1.Draw the grid on the screen 
2.Mark cells that have obstacles in 
  it 
3.Find and add the neighbours of the
  cell
4.Find the path for the zombie by 
  using the breathFirstSearch 
------------------------------------
1.Obstacle
2.Cell

#HUD
====================================
1.Draw the number of bullet left 
  for player to use 
------------------------------------
None

#Menu
====================================
1.The main menu of the game
2.Shows option to player 
3.Can go to gameplay or character 
  selection
------------------------------------
None

#Obstacle
=====================================
1.Contain all the obstacle like walls,
  container and stone 
2.Draw rectangle shape on top of
  obstacles
3.Get the 4 corners of the rectangle 
  shape to be use by Grid
-------------------------------------
None

#Particles
=====================================
1.Explosion effect when the gun is 
  shot, particles will appear on 
  screen for a few seconds
2.Draw the particle 
3.Update the particle
--------------------------------------
None

#Player
======================================
1.Tell the player chracter to move , 
  shoot or sneak(move stealthily)
2.Die if hit by zombie 
3.Not allowed to leave the screen
4.Have animation for the player
--------------------------------------
Animation

#ScreenSize
======================================
1.Have the size of the screen 
--------------------------------------
None

#Zombie
======================================
1.Have health 
2.Have animation for the zombie 
3.Go to the destination Cell
======================================
1.Animation



