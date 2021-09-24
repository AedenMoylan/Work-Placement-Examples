AmmoBox Class

@startuml
Class AmmoBox
{
+void init();
+void draw(sf::RenderWindow& window);
+void getIsAmmoCollected();
+void setIsAmmoCollected(bool hasPlayerCollect);
+sf::Sprite getSprite();
}

Class Game
{
+Game();
+void run();
}

Class Bullet
{
+void init();
+void draw(sf::RenderWindow& window;
+void setBulletPosition(sf::Sprite t_playerSprite);
+void update();
+void setRotation(sf::Sprite t_playerSprite);
+void moveBullet();
+int getCounter();
+void setIsBulletActive(bool _i);
+void setCounter(int _i);
+sf::Sprite bulletSprite;
+sf::Texture bulletTexture;
}

AmmoBox --> Game
Game --> Bullet
Bullet -->Game
Game -->AmmoBox
@enduml

![image](https://user-images.githubusercontent.com/58420356/115864641-0fc63c00-a42f-11eb-82b5-db6af438db87.png)


-------------------------------------------------------------------------
Animation and AnimationSheet Class

@startuml
Class Animation
{
+int numframes'
+int startOffset;
+double speed;
+bool loop:
}

CLass AnimationSheet
{
+void Init(int _pixelWidth , int _pixelHeight , int _numRows , int _numCols);
+sf::IntRect GetFrame();
+void StartAnimation(Animation curAnimation);
+void nextFrame();
}

Animation <-- AnimationSheet
AnimationSheet --> SFML
@enduml

![image](https://user-images.githubusercontent.com/58420356/115864585-f3c29a80-a42e-11eb-9ae4-ceef2c2db26c.png)


----------------------------------------------------------------------------

Background Class 

@startuml
Class Background 
{
+void backgroundInIt();
+void draw(sf::RenderWindow& win);
+void drawVictory(sf::RenderWindow& win);
+void drawLose(sf::RenderWindow& win);
}

Background ..> SFML
@enduml

![image](https://user-images.githubusercontent.com/58420356/115864544-e5747e80-a42e-11eb-8425-f8c7276d1b6b.png)


-------------------------------------------------------------------------------

Bullet Class

@startuml
Class Bullet
{
+void init();
+void draw(sf::RenderWindow& window;
+void setBulletPosition(sf::Sprite t_playerSprite);
+void update();
+void setRotation(sf::Sprite t_playerSprite);
+void moveBullet();
+int getCounter();
+void setIsBulletActive(bool _i);
+void setCounter(int _i);
+sf::Sprite bulletSprite;
+sf::Texture bulletTexture;
}

Bullet ..> SFML.Graphics
Bullet ..> MathUtility 
MathUtility ..> thor
Bullet ..> functional

@enduml

![image](https://user-images.githubusercontent.com/58420356/115864498-d42b7200-a42e-11eb-8149-fe4619d744e6.png)


-------------------------------------------------------------------------------------------

Cell Class

@startuml
Class Cell
{
+void setPassable(bool t_isPassable);
+void setId(int Id);
+void senCentre(sf::Vector2f t_centre);
+void setMarked(bool t_isMarked);
+void addNeighbours(int t_cellId);
+std::vector<int>& neighbours();
+int id();
+bool isMarked() const;
+int previous() const;
+void setPrevious(int t_previous);
+sf::Vector2f getPosition();
+bool getPassable() const;
}

Cell ..> vector 
Cell ..> SFML.Graphics
@enduml

![image](https://user-images.githubusercontent.com/58420356/115864464-c8d84680-a42e-11eb-9b33-a27511855f78.png)

--------------------------------------------------------------------------------------

CharacterSelection Class

@startuml
Class CharacterSelection
{
+void setupSprites(sf::Font& font);
+void draw(sf::RenderWindow& window);
+void update(sf::Window& window);
+static const int m_optionCount = 3;
+sf::Texture m_buttonTexture;
+sf::Sprite m_buttonSprites[m_optionCount];
+sf::Font m_font;
+sf::Text m_buttonTexts[m_optionCount];
+float m_topOffset;
+float m_leftOffset;
+float m_horizontalSpacing;
+float m_buttonWidth;
+float m_buttonHeight;
+int getSelectionNumber();
}

CharacterSelection ..> SFML.Graphic
CharacterSelection ..> iostream
@enduml

![image](https://user-images.githubusercontent.com/58420356/115864417-ba8a2a80-a42e-11eb-8fda-5abb945398f0.png)


-------------------------------------------------------------------------------

CollisionDetection Class

@startuml
Class CollisionDetection
{
+bool player_ammoBox_Collision(sf::Sprite& playerSprite, sf::Sprite& ammoBoxSprite);
+bool player_greenContainer_Collision(sf::Sprite& playerSprite, sf::Sprite& greenContainer);
+bool player_obstacle_Collision(sf::Sprite& playerSprite, sf::RectangleShape obstacles);
+bool bullet_zombie_Collision(sf::Sprite& bulletSprite, sf::Sprite& zombieSprite);
+bool player_zombie_Collision(sf::Sprite& playerSprite, sf::Sprite& zombieSprite);
+bool bullet_obstacle_collision(sf::Sprite& bulletSprite, sf::RectangleShape obstacles);
}

CollisionDetection ..> SFML.Graphic
@enduml

![image](https://user-images.githubusercontent.com/58420356/115864395-af36ff00-a42e-11eb-8c49-f2702ac9192e.png)


----------------------------------------------------------------------------------------


Menu Class

@startuml
Menu : + void initialise(sf::Font&);
Menu : + void draw(sf::RenderWindow&);
Menu : + void update(sf::Window&);
Menu : + void playMusic();
Menu : + void changeVolume();
Menu : + void getSelectionNumber();

Menu ..> SFML.Graphics
Menu ..> SFML.Audio
Menu ..> Iostream
@enduml


![image](https://user-images.githubusercontent.com/58327062/115865196-e823a380-a42f-11eb-9c48-0c844abf8b8e.png)

..............................................

Zombie Class

@startuml
Zombie : +	enum class ZombieAnimationState { walk, run, jump, idle };
Zombie : +	ZombieAnimationState animationState = ZombieAnimationState::walk;
Zombie : +	Animation animations[5];
Zombie : +	AnimationSheet animSheet;
Zombie : +	sf::Sprite& spriteSheet;
Zombie : + void init();
Zombie : + 	sf::Texture zombieTextureSheet;
Zombie : + 	sf::Sprite zombieSpriteSheet;
Zombie : +  	void InitAnimationData();
Zombie : +	void startAnimation(ZombieAnimationState _animationState);
Zombie : + 	void Draw(sf::RenderWindow& win);
Zombie : + 	int getHealth();
Zombie : + 	void reduceHealth();
Zombie : + 	sf::Vector2f getPosition();
Zombie : + 	void move(sf::Vector2f _targetLocation);

AnimationSheet ..> Animation
  Animation : + int numframes; 
  Animation : + int startOffset; 
  Animation : + double speed; 
  Animation : + bool loop;

Zombie -> AnimationSheet
AnimationSheet : +  void Init(int _pixelWidth, int _pixelHeight, int _numRows, int _numCols);

 AnimationSheet : +  sf::IntRect GetFrame();

 AnimationSheet : +   void StartAnimation(Animation curAnimation);

   AnimationSheet : + void nextFrame();

AnimationSheet ..> SFML.Graphics

Zombie ..> SFML.Audio
@enduml


![image](https://user-images.githubusercontent.com/58327062/115871316-494f7500-a438-11eb-8cce-287b52f75128.png)


--------------------------------------------

Player Class

@startuml
Player : + 	sf::Sprite playerSpriteSheet;
Player : +	enum class PlayerAnimationState { walk, run, jump, idle };
Player : +	PlayerAnimationState animationState = PlayerAnimationState::walk;
Player : +	Animation animations[5];
Player : +	AnimationSheet animSheet;
Player : +	sf::Vector2f position;
Player : +	sf::Sprite& spriteSheet;
Player : + 	void InitAnimationData();
Player : + 	void startAnimation(PlayerAnimationState _animationState);
Player : +     	void Draw(sf::RenderWindow& win);
Player : + 	void Update();
Player : + 	void init();
Player : + 	void updateSpeed(int speed);
Player : +	void chooseTexture(int selectioNumber);
Player : + 	void playGunSound();

  Animation : + int numframes; 
  Animation : + int startOffset; 
  Animation : + double speed; 
  Animation : + bool loop;

AnimationSheet ..> Animation
Player -> AnimationSheet
AnimationSheet : +  void Init(int _pixelWidth, int _pixelHeight, int _numRows, int _numCols);

 AnimationSheet : +  sf::IntRect GetFrame();

 AnimationSheet : +   void StartAnimation(Animation curAnimation);

   AnimationSheet : + void nextFrame();

AnimationSheet ..> SFML.Graphics

Player ..> SFML.Audio
@enduml


![image](https://user-images.githubusercontent.com/58327062/115871992-2bcedb00-a439-11eb-92e5-4b27d1ae87fe.png)


--------------------------------------------------------------------------------------

Particle Class

@startuml
Particle : +  void Draw(sf::RenderWindow& win);
Particle : +  void Update();
Particle : +  Particles() {}
Particle : +  Particles(sf::Vector2f pos, sf::Vector2f vel);

ParticleSystem : +     Particles particles[maxParticles];
ParticleSystem : +     sf::Vector2f position;
ParticleSystem : +     void Initialise(sf::Vector2f pos);
ParticleSystem : +     void Update();
ParticleSystem : +     void Draw(sf::RenderWindow& win);
ParticleSystem : +     ParticleSystem() {};
ParticleSystem : +     maxParticles 50;

ParticleSystem ..> Particle
Particle ..> SFML.Graphics
@enduml

![image](https://user-images.githubusercontent.com/58327062/115872342-9b44ca80-a439-11eb-9c83-75e92cac2f35.png)


---------------------------------------------------------------------------------------



Game Obstacle

@startuml
Obstacle : + 	void init();
Obstacle : + 	void draw(sf::RenderWindow& window);
Obstacle : + 	sf::RectangleShape obstacles[MAX_OBSTACLES];
Obstacle : + 	sf::Vector2f getTopLeft(int obstacle_num);
Obstacle : + 	sf::Vector2f getTopRight(int obstacle_num);
Obstacle : + 	sf::Vector2f getBottomLeft(int obstacle_num);
Obstacle : + 	sf::Vector2f getBottomRight(int obstacle_num);
Obstacle : + 	sf::Sprite getContainerSprite();
Obstacle : + 	sf::RectangleShape getObstacles(int _i);
Obstacle : + 	const static int getMaxObstacles();

Obstacle ..> SFML.Graphics
Obstacle ..> ScreenSize
ScreenSize : + 	static const int s_width{ 1050 };
ScreenSize : +	static const int s_height{ 850 };
@enduml

![image](https://user-images.githubusercontent.com/58327062/115872482-c4fdf180-a439-11eb-9704-6a7799f9c412.png)


------------------------------------------------------------------------------------


MathUtility Class
@startuml
MathUtility ..> SFML.Graphics
MathUtility ..> SFML.Vector2
MathUtility ..> THOR.Vectors
@enduml

![image](https://user-images.githubusercontent.com/58327062/115872710-042c4280-a43a-11eb-9ea8-6c387e70f1a3.png)


--------------------------------------------------------------------------------------
HUD Class

@startuml
HUD : + int numBulletsToDraw;
HUD : +	void init(sf::Font& font);
HUD : +	void draw(sf::RenderWindow& window, bool canBulletsBeDrawn);
HUD : +	void update();

HUD ..> SFML.Graphics
HUD ..> Iostream
@enduml

![image](https://user-images.githubusercontent.com/58327062/115872809-24f49800-a43a-11eb-8c1f-dab5e715d14a.png)


------------------------------------------------------------------------------------------


Grid Class

@startuml
Grid : +	        Grid();
Grid : +	        void init();
Grid : +	        void draw(sf::RenderWindow& window);
Grid : +	        void markImpassableCells(Obstacle& myObstacle);
Grid : +	        void neighbours(int t_row , int t_col);
Grid : +	        std::vector<int>breadthFirst(int t_startCellId, int t_destCellId);
Grid : +	        std::vector<Cell> getCells();

Grid ..> Cell
Grid -> Obstacle

Obstacle : + 	void init();
Obstacle : + 	void draw(sf::RenderWindow& window);
Obstacle : + 	sf::RectangleShape obstacles[MAX_OBSTACLES];
Obstacle : + 	sf::Vector2f getTopLeft(int obstacle_num);
Obstacle : + 	sf::Vector2f getTopRight(int obstacle_num);
Obstacle : + 	sf::Vector2f getBottomLeft(int obstacle_num);
Obstacle : + 	sf::Vector2f getBottomRight(int obstacle_num);
Obstacle : + 	sf::Sprite getContainerSprite();
Obstacle : + 	sf::RectangleShape getObstacles(int _i);
Obstacle : + 	const static int getMaxObstacles();

Obstacle ..> SFML.Graphics
Obstacle ..> ScreenSize
ScreenSize : + 	static const int s_width{ 1050 };
ScreenSize : +	static const int s_height{ 850 };

Class Cell
{
+void setPassable(bool t_isPassable);
+void setId(int Id);
+void senCentre(sf::Vector2f t_centre);
+void setMarked(bool t_isMarked);
+void addNeighbours(int t_cellId);
+std::vector<int>& neighbours();
+int id();
+bool isMarked() const;
+int previous() const;
+void setPrevious(int t_previous);
+sf::Vector2f getPosition();
+bool getPassable() const;
}

Cell ..> vector 
Cell ..> SFML.Graphics
@enduml


![image](https://user-images.githubusercontent.com/58327062/115873011-5bcaae00-a43a-11eb-87c6-a886673ec1c0.png)

----------------------------------------------------


Game Class

@startuml
Class Game
{
+Game();
+void run();
}

Class CollisionDetection
{
+bool player_ammoBox_Collision(sf::Sprite& playerSprite, sf::Sprite& ammoBoxSprite);
+bool player_greenContainer_Collision(sf::Sprite& playerSprite, sf::Sprite& greenContainer);
+bool player_obstacle_Collision(sf::Sprite& playerSprite, sf::RectangleShape obstacles);
+bool bullet_zombie_Collision(sf::Sprite& bulletSprite, sf::Sprite& zombieSprite);
+bool player_zombie_Collision(sf::Sprite& playerSprite, sf::Sprite& zombieSprite);
+bool bullet_obstacle_collision(sf::Sprite& bulletSprite, sf::RectangleShape obstacles);
}

Class CharacterSelection
{
+void setupSprites(sf::Font& font);
+void draw(sf::RenderWindow& window);
+void update(sf::Window& window);
+static const int m_optionCount = 3;
+sf::Texture m_buttonTexture;
+sf::Sprite m_buttonSprites[m_optionCount];
+sf::Font m_font;
+sf::Text m_buttonTexts[m_optionCount];
+float m_topOffset;
+float m_leftOffset;
+float m_horizontalSpacing;
+float m_buttonWidth;
+float m_buttonHeight;
+int getSelectionNumber();
}

Class Bullet
{
+void init();
+void draw(sf::RenderWindow& window;
+void setBulletPosition(sf::Sprite t_playerSprite);
+void update();
+void setRotation(sf::Sprite t_playerSprite);
+void moveBullet();
+int getCounter();
+void setIsBulletActive(bool _i);
+void setCounter(int _i);
+sf::Sprite bulletSprite;
+sf::Texture bulletTexture;
}

Class Background 
{
+void backgroundInIt();
+void draw(sf::RenderWindow& win);
+void drawVictory(sf::RenderWindow& win);
+void drawLose(sf::RenderWindow& win);
}

Class AmmoBox
{
+void init();
+void draw(sf::RenderWindow& window);
+void getIsAmmoCollected();
+void setIsAmmoCollected(bool hasPlayerCollect);
+sf::Sprite getSprite();
}

Class Zombie
{
+    enum class ZombieAnimationState { walk, run, jump, idle };
+    ZombieAnimationState animationState = ZombieAnimationState::walk;
+    Animation animations[5];
+    AnimationSheet animSheet;
+    sf::Sprite& spriteSheet;
+ void init();
+     sf::Texture zombieTextureSheet;
+     sf::Sprite zombieSpriteSheet;
+      void InitAnimationData();
+    void startAnimation(ZombieAnimationState _animationState);
+     void Draw(sf::RenderWindow& win);
+     int getHealth();
+     void reduceHealth();
+     sf::Vector2f getPosition();
+void move(sf::Vector2f _targetLocation);
}
Class Player
{
+     sf::Sprite playerSpriteSheet;
+    enum class PlayerAnimationState { walk, run, jump, idle };
+    PlayerAnimationState animationState = PlayerAnimationState::walk;
+    Animation animations[5];
+    AnimationSheet animSheet;
+    sf::Vector2f position;
+    sf::Sprite& spriteSheet;
+     void InitAnimationData();
+     void startAnimation(PlayerAnimationState _animationState);
+         void Draw(sf::RenderWindow& win);
+     void Update();
+     void init();
+     void updateSpeed(int speed);
+    void chooseTexture(int selectioNumber);
+     void playGunSound();
}

Class ParticleSystem
{
+     Particles particles[maxParticles];
+     sf::Vector2f position;
+     void Initialise(sf::Vector2f pos);
+     void Update();
+     void Draw(sf::RenderWindow& win);
+     ParticleSystem() {};
+     maxParticles 50;
}

Class Obstacle 
{
+     void init();
+     void draw(sf::RenderWindow& window);
+     sf::RectangleShape obstacles[MAX_OBSTACLES];
+     sf::Vector2f getTopLeft(int obstacle_num);
+     sf::Vector2f getTopRight(int obstacle_num);
+     sf::Vector2f getBottomLeft(int obstacle_num);
+     sf::Vector2f getBottomRight(int obstacle_num);
+     sf::Sprite getContainerSprite();
+     sf::RectangleShape getObstacles(int _i);
+     const static int getMaxObstacles();
}

Class Menu 
{
+ void initialise(sf::Font&);
+ void draw(sf::RenderWindow&);
+ void update(sf::Window&);
+ void playMusic();
+ void changeVolume();
+ void getSelectionNumber();
}

Class ScreenSize 
{
+     static const int s_width{ 1050 };
+    static const int s_height{ 850 };
}
Class HUD 
{
+ int numBulletsToDraw;
+    void init(sf::Font& font);
+    void draw(sf::RenderWindow& window, bool canBulletsBeDrawn);
+    void update();
}

Class Grid 
{
+            Grid();
+            void init();
+            void draw(sf::RenderWindow& window);
+            void markImpassableCells(Obstacle& myObstacle);
+            void neighbours(int t_row , int t_col);
+            std::vector<int>breadthFirst(int t_startCellId, int t_destCellId);
+            std::vector<Cell> getCells();
}

Class GameState
{
+GAME_RUNNING,
+GAME_WIN,
+GAME_LOSE,
+GAME_MENU,
+CHARACTER_OPTION,
}

Game ..> SFML.Graphics
Game ..> SFML.Audio
ScreenSize ..> Game
Zombie ..> Game
Background ..> Game
Player ..> Game
AmmoBox ..> Game
CollisionDetection ..> Game
Bullet ..> Game
Obstacle ..> Game
GameState ..> Game
Menu ..> Game
ParticleSystem ..> Game
HUD ..> Game
CharacterSelection ..> Game
Grid ..> Game
@enduml

Link for full image:

http://www.plantuml.com/plantuml/svg/jLXRRziu4ttth-1JuA16qUzR55YaswAEaoO6uYI8adQnGI7GqjZYbY85aigbGV_xYXUFHCTHrGNMBoPdpXoICuSN-wCsL9cwvACPfrgJ4rh2w6dqodwFzz-DNjr9bXDL2zlvCGgecUISQIR54HZ8JDEmCKifEQauVGILqhAKX_8XHUHOhmuEaaen0ti1v7iJqlM4EDzjXen8rmf0pAGmb0bGlymTXs-JowKsDECmcFOACaF5caDIq0h89buZyRBc74pwNPPBzXAjn-oQhG_RdOXUIeyPI8cpnELdFVCSiln89mLLD3EW4k2e4oyf3QQkF9zs8tsImkoHbHG6PPShUZ_sOuaSr1ScSdc_H-xTDwBgAgS67EuvGXjgM4OoARGXJ1XIfhAo4vd9kkcz9xyr81jw3G-cLj3ubxKnKeI-zM8Qq1dcVHkHVGrOkv06QLVIuOw8TqIkkAGMP6HriLffC1qRXvLvPYoaOj-jc7bIqOo9zSQ78trXkIcUMK-1hGjBPBEn1eEbEQ_B9QXedn-wgcFDc61cFAmwxzeoUv9BgPc9LKLCsjNgTa7tEnnNqj21qQMy0pzamu2hT7a65P7EjSTDCyFkOEnsGyew28oo9DxJZXzjYLX4mHLwtNpIxDjQDQGvmQGkqJONyq7fZI2VMMQaUXo0F9CQNeJX5AV-0FutDKVKskRM4ja32Z83UPptsESJNr1zwSePx76oBQLlHVhyonreTgwa-O2eIv9r75F1IYURn503v8dSK_vjOc-p2VcxBgi9OJa7ykETZzyPHEFk-vseWmFB76ZGrSRgsxTVjxr90M0SnBMyEpgkjVj6RrmEuj6ekN2uXnu6nPpH3H1XFFkyOSS97b53SIZdTcy5z8ztvYkD4-RYaU2eJzCU5_RhAL1kYd4ShY2lCzXsMRxFO7V1_rSs54-Qw4WOHx3KKDL0psJcfcer5IJbHUWb5USEJnlCNImx3Fv5sM5Gh-mGzP_93fDJXGJ-N983XBDJERYO8SePgXx4tU3zWSRjZTEvPv8A87SdlBQjIF1P8QNUx2cF2RUblonZFYkGareazYoFZgbBgWpBE2IFsa29sjgODQashTkIFg3PrwwdEd7-6ULCmtWRt9-ReOcDbp3U9qy_DgxkbCdRDvrrNuGteRtiUalHVwyWjE_PURkO_fbU72RNqzdPSVBrfSFXMbPdi3AsbXYRYhhSxmcuiW-cuH67qXXPHgCCZ1amK7iTuWyPRnhtPCd2DxNG-9ZnyF0q3k_aSFekw0FY8oKlGDI-cg6IA3jymblYlgAs_lZXZZxSIujQispSshAYMH9ybhmkeJN_x0sRP0f09EnxHuRFVXNezDu-bf_8_zwyVOCdymvOuLxFJ-Ht1yDRu_JcoBDRbAXB_x3Krz9khS266TlnSsVOHfWGzrJAg0ZyXs3vHSk0MOrISA9O7XQF7sUqA3H6SumymsQtCwAawjkyhAZMTCbX1fphyKPQUwHytBHt1WkRxAMibHUjIPMy9nFYsvdasq7Qv0S7TsvR_T60FYmLqDmKdvZI9Z2uYyXEOvvlY7BGmTB7Pn4VhDRy6gBqqXBibUN_E9akZjEhc_Fp-Vd997I_pCytpREBv7ZJNXoVtpJjsUdqQZgxFhvABowlvnSDj66sdEJrwmya-RGuUtsYQ5MmJ6-PftNEv0W5xZqMCl9FixRV-U61Ddy9j_tmycyDp__bQNrUW6qVZtgqO5PQapizi1TVAQtTxYNiFFy7eVKvMMFl8uYyBla_
