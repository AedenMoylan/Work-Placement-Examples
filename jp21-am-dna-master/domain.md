@startuml
Class AmmoBox
{
-Appear on the screen
-Give ammo to player when collected 
}

Class Animation
{
-Get the next frame to be animated
-Know which frame , how fast and if the animation need to be on loop 
-Crop the image based on which part of the iamge is needed from the sprite sheet
}

Class Background
{
-Render the background iamges based on the gamestate
}

Class Bullet
{
-Can be shoot by the player 
-Can collide with zombie 
-Can collide with obstacle
}

Class Cell
{
-Contain all the variables need by a cell 
}

Class CharacterSelection
{
-Is a screen that shows all the characters that can be use by the player
}

Class CollisionDetection
{
-Handle all the collisions
}

Class Game 
{
-The game controller 
}

Class GameState
{
-Is an enum class for all the possible game states
}

Class Grid
{
-Draw the grid on the screen
-Mark cells that have obstacle in it
-Find and add the neighbours of the cell
-Find the path for the zombie by using the breathFirstSearch
}

Class HUD
{
-Draw the number of bullet left for player to use
}

Class Menu
{
-The main manu of the game
-Shows options to player 
-Can go to gameplay or character selection screen
}

Class Obstacle
{
-Contain all the obstacles like walls , container and stone 
-Draw the rectangle shape on top of the obstacles 
-Get the 4 corners of the rectangle shape to be use by grid
}

Class Particles
{
-Explosions effect when the gun is shot , particle will appear on screen for a few seconds 
-Draw the particle 
-Update the particle
}

Class Player 
{
-Tell the player character to move , shoot and sneak(move stelthily)
-Die if hit by zombie 
-Not allowed to leave the screen
-Have animation for the player
}

Class ScreenSize
{
-Have the size of the screen
}

Class Zombie 
{
-Have health 
-Have aniamtion for the zombie 
-Go to destination cell
}

Player --> Bullet
Player --> CollisionDetection
Zombie --> CollisionDetection
AmmoBox --> CollisionDetection
Bullet --> CollisionDetection
Player --> Game
Zombie --> Game
AmmoBox --> Game
Bullet --> Game
ScreenSize--> Game
Background --> Game
CollisionDetection --> Game
Obstacle --> Game
GameState --> Game
Menu --> Game
Particles --> Game
CharacterSelection --> Game
Grid --> Game
HUD --> Game
Obstacle --> Grid
Cell --> Grid
Animation --> Player
Animation --> Zombie

@enduml

http://www.plantuml.com/plantuml/png/TLR1RkGs3BtxAtXiWSojvs9tasvI5DiMdUwbDzhYZ8N8aY7HusIB_difMhOycynH9FKU-KZH_f0O8q-3Q-uTfWGVXo5y2Y_DlytXupWIHWWUk2T8NIJopU7HNWXGee03Z0vVASBSauSkE4STau7clsP5ytP0ji5dl4TYHVBqmd2AE526Q0LDeyWqXzzyc0NDTdq9k8DUB2TCB546x4aHS8KLB385HKukX16QmtqCeyP9r9cWnKH6t0LunCWG5Y2BWmJOf3XaX3GCIxLZj4oGUYAkvNp2xlaSm-HDhkSlyeQYXhUROu5CbJIxppXGOcJQGKtE4MUOU_JGPgeG6DfNlL1qLQSAQmt1RBc7Rs5eBRtd2QrGT6x7SK_EAKFmZDO3EgVe5umMMqTBsPaJeIDnxgxs6B5ZYaTorAqT_3K1ba4G8EISz9mst6wzb1PljrGs9RgkQqUJ2qY2_a1SQPxG6qSLTWrAzU9Z7euS-tUHLw8yHuca2DTXHnM-PE-1_3H0fzvJY1l965AohIjWsgmzNRJQyeU8yz9HCNp_ChvWV5OTI_azNcZh2bWFbfl3P-kDZZ8QKrw3FVTjc68gGwaG9L0pG-urrNpGzgkSKxB-hBOsaeHyjZ7naJ1sVStxwUl3LTfIUqin4xKwV-3en0fU9ew305C5-49-McKUyWmDw2TDjEZU78uw0s7at241k1xUSn2JHcOpX5Yd1D8wMqN2Ilj7KUtjz5P54pZxJ31Z5lmEkYMCeggRE7Y2NULHcD2VNNveE9BsBenh9HMphgcV139wgdtv7e93dMuTY9h_dnZPPhnSm2ylemj9rQ7JIK1qNouAJXvi4hp0Ki9ORi5idGDSrszHPnbNED4CYQHQa_RrhNV5zdKqo7HbtMLMcfDxIixjjqrj30SOmeNWhcmbLTGJFl-WviJakBVkzKT9m5BUohtDkwjkfz_pBUV2lAndHtYXgyVo98QwnxMsznR4KSEFzXlfOjXGn53QycPs_YavhF4zeMGBbHA7FMND-L57rL1YwpKhVOaPk8XsEFoyxkrgUM-7bHHkUCidzfPxORZbhSIwt2hLSgxWnL3WwhagMaFgrskplQMkllLrLiksPwifRuvwsXv4DRtznEpmejtb8bli1hdkvVoPgwVjbqDDYrpNnZ8XpGVoPXhS_m00

![image](https://user-images.githubusercontent.com/58420356/115802098-27bda180-a3d6-11eb-86b1-152d2db180f0.png)

![image](https://user-images.githubusercontent.com/58420356/115802929-b41c9400-a3d7-11eb-8a48-9fe59110becb.png)

Link below for full image:
http://www.plantuml.com/plantuml/svg/TLR1RkGs3BtxAtXiWSojvs9tasvI5DiMdUwbDzhYZ8N8aY7HusIB_difMhOycynH9FKU-KZH_f0O8q-3Q-uTfWGVXo5y2Y_DlytXupWIHWWUk2T8NIJopU7HNWXGee03Z0vVASBSauSkE4STau7clsP5ytP0ji5dl4TYHVBqmd2AE526Q0LDeyWqXzzyc0NDTdq9k8DUB2TCB546x4aHS8KLB385HKukX16QmtqCeyP9r9cWnKH6t0LunCWG5Y2BWmJOf3XaX3GCIxLZj4oGUYAkvNp2xlaSm-HDhkSlyeQYXhUROu5CbJIxppXGOcJQGKtE4MUOU_JGPgeG6DfNlL1qLQSAQmt1RBc7Rs5eBRtd2QrGT6x7SK_EAKFmZDO3EgVe5umMMqTBsPaJeIDnxgxs6B5ZYaTorAqT_3K1ba4G8EISz9mst6wzb1PljrGs9RgkQqUJ2qY2_a1SQPxG6qSLTWrAzU9Z7euS-tUHLw8yHuca2DTXHnM-PE-1_3H0fzvJY1l965AohIjWsgmzNRJQyeU8yz9HCNp_ChvWV5OTI_azNcZh2bWFbfl3P-kDZZ8QKrw3FVTjc68gGwaG9L0pG-urrNpGzgkSKxB-hBOsaeHyjZ7naJ1sVStxwUl3LTfIUqin4xKwV-3en0fU9ew305C5-49-McKUyWmDw2TDjEZU78uw0s7at241k1xUSn2JHcOpX5Yd1D8wMqN2Ilj7KUtjz5P54pZxJ31Z5lmEkYMCeggRE7Y2NULHcD2VNNveE9BsBenh9HMphgcV139wgdtv7e93dMuTY9h_dnZPPhnSm2ylemj9rQ7JIK1qNouAJXvi4hp0Ki9ORi5idGDSrszHPnbNED4CYQHQa_RrhNV5zdKqo7HbtMLMcfDxIixjjqrj30SOmeNWhcmbLTGJFl-WviJakBVkzKT9m5BUohtDkwjkfz_pBUV2lAndHtYXgyVo98QwnxMsznR4KSEFzXlfOjXGn53QycPs_YavhF4zeMGBbHA7FMND-L57rL1YwpKhVOaPk8XsEFoyxkrgUM-7bHHkUCidzfPxORZbhSIwt2hLSgxWnL3WwhagMaFgrskplQMkllLrLiksPwifRuvwsXv4DRtznEpmejtb8bli1hdkvVoPgwVjbqDDYrpNnZ8XpGVoPXhS_m00


