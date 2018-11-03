#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Animation.h"
#include "Player.h"
#include "Soldier.h"
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Projectile.h"
#include "Enemy.h"
#include <cstdlib>
#include <ctime>
#include "Random.h"
#include "TextDisplay.h"
#include <string>
using namespace std;
class TileMap : public sf::Drawable, public sf::Transformable
{
public:

    bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
    {
        // load the tileset texture
        if (!m_tileset.loadFromFile(tileset))
            return false;

        // resize the vertex array to fit the level size
        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(width * height * 4);

        // populate the vertex array, with one quad per tile
        for (unsigned int i = 0; i < width; ++i)
            for (unsigned int j = 0; j < height; ++j)
            {
                // get the current tile number
                int tileNumber = tiles[i + j * width];

                // find its position in the tileset texture
                int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
                int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

                // get a pointer to the current tile's quad
                sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

                // define its 4 corners
                quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
                quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
                quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

                // define its 4 texture coordinates
                quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
                quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
                quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
            }

        return true;
    }

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // apply the transform
        states.transform *= getTransform();

        // apply the tileset texture
        states.texture = &m_tileset;

        // draw the vertex array
        target.draw(m_vertices, states);
    }

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};

int main(){

    ///just timers ajio...
    sf::Clock clock1;
    sf::Clock clock2;
    sf::Clock clock3;
    ///contadores ajio....
    int counter = 0;
    int counter1 = 0;
    int counter2 = 0;
    //srand((int)time(0));

    sf::RenderWindow Window(sf::VideoMode(1280, 704), "Animation Test!", sf::Style::Close | sf::Style::Resize);
    Window.setFramerateLimit(60); ///60 fps perro

    sf::RectangleShape Enemytest(sf::Vector2f(25.0f, 36.0f)); //clase
    Enemytest.setPosition(1150.0f, 550.0f); //clase
    sf::Texture EnemyTexture; //out
    EnemyTexture.loadFromFile("EnemyStand.png");//out
    Enemytest.setTexture(&EnemyTexture);
    Animation AnimationEnemy(&EnemyTexture, sf::Vector2u(6,1), 0.2f);
    ///animacion de la gemilla
    sf::RectangleShape gemtest(sf::Vector2f(50.0f, 50.0f)); //clase
    gemtest.setPosition(1150.0f, 650.0f); //clase
    sf::Texture GemTexture; //out
    GemTexture.loadFromFile("gema.png");//out
    gemtest.setTexture(&GemTexture);
    Animation AnimationGEM(&GemTexture, sf::Vector2u(7,6), 0.2f);










    ///inicializador de sonido lml
    sf::SoundBuffer bufferFireBall;
    if (!bufferFireBall.loadFromFile("FlameMagic.ogg"))
        return -1;

    sf::Sound soundFireBall;
    soundFireBall.setBuffer(bufferFireBall);

    sf::Music music;
    if (!music.openFromFile("BloodyTears.ogg"))
        return -1;
    music.play();
    music.setVolume(100.f);


    //inicializador del power 1 ( bolita de fuego)
    sf::Texture TexturePower1;
    if (!TexturePower1.loadFromFile("FireBall.png"))
    {
        return EXIT_FAILURE;
    }

    //fuente
    sf::Font Fuente;
    if(!Fuente.loadFromFile("coneria2.ttf")){

        return EXIT_FAILURE;
    }

    float deltatime = 0.0f;
    sf::Clock clock;
    //variables de inicilizar jugador
    sf::Texture TextureSoldier;
    if (!TextureSoldier.loadFromFile("we.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Sprite spriteSoldier(TextureSoldier);
    spriteSoldier.setPosition(Window.getSize().x/2, Window.getSize().y/2); //pos del sprite del soldado
    spriteSoldier.setTextureRect(sf::IntRect(0,0,32,48)); //chek

    //inicializador del jugador
    Soldier soldado(0.0f, 600.0f);
    soldado.SPRITE.setTexture(TextureSoldier);

    //variables de inicializar enemigo
    sf::Texture TextureEnemy;
    if (!TextureEnemy.loadFromFile("Enemy.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Sprite spriteEnemy(TextureEnemy);
    spriteEnemy.setPosition(Window.getSize().x/2, Window.getSize().y/2); //pos del sprite del soldado
    spriteEnemy.setTextureRect(sf::IntRect(0,0,32,48)); //chek


    //Enemy Enemigo2;
    //Enemigo.SPRITE.setTexture(TextureEnemy);


    //incializador de array projectile
    vector<Projectile>::const_iterator Iterador;
    vector<Projectile> projectileArray;
    //inicializador de objeto projectile
    Projectile Power1;
    Power1.SPRITE.setTexture(TexturePower1);/// seteo el sprite de la bola de fuego al object.

    //incializador del array enemigo
    vector<Enemy>::const_iterator IteradorE;
    vector<Enemy> EnemyArray;
    //inicializador de objeto enemigo
    Enemy Enemigo;
    Enemigo.SPRITE.setTexture(TextureEnemy);
    //Enemigo.RECT.setPosition(500, 600);
    EnemyArray.push_back(Enemigo);


    //inicializador del array text
    vector<TextDisplay>::const_iterator IteradorT;
    vector<TextDisplay> TextArray;
    //inicializador de objeto text
    TextDisplay TextDISPLAY1;
    TextDISPLAY1.TEXT.setFont(Fuente);
    ///TextDISPLAY1.TEXT.setString();

    const int level[] =
    {
        0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0, 0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0, 0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
        2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0, 0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0, 0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
        2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 3, 3, 3, 3, 0,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 3, 3, 3, 3, 0,
        3, 3, 3, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0, 0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 3, 3, 3, 3, 0,
        3, 3, 3, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 3, 3, 3, 3, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 3, 3, 3, 0,
        3, 3, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 3, 3, 3, 3, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 3, 3, 3, 0,
        3, 3, 3, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 3, 3, 3, 3, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 3, 3, 3, 3, 0,
        3, 3, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 3, 3, 3, 3, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 3, 3, 3, 3, 3, 0,
        3, 3, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 3, 3, 0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 3, 3, 3, 3, 3, 0,
    };

    TileMap map;
    if (!map.load("tileset2.png", sf::Vector2u(32, 32), level, 40, 22))
        return -1;

    while(Window.isOpen()){

        deltatime = clock.restart().asSeconds();
        sf::Event EVENTO;
        while(Window.pollEvent(EVENTO)){

            switch(EVENTO.type){

                case sf::Event::Closed:
                Window.close();
                break;
            }
        }

        AnimationEnemy.UpDate(0,deltatime, true);
        AnimationGEM.UpDate(0,deltatime,true);

        Enemytest.setTextureRect(AnimationEnemy.uvRect);
        gemtest.setTextureRect(AnimationGEM.uvRect);


        Window.clear();
        Window.draw(map);
        /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)){

            Enemigo.RECT.setPosition(generateRandom(Window.getSize().x), generateRandom(Window.getSize().y));
            EnemyArray.push_back(Enemigo);
        }*/
        ///clocks yeeey...
        sf::Time elapsed1 = clock1.getElapsedTime();
        sf::Time elapsed2 = clock2.getElapsedTime();
        sf::Time elapsed3 = clock3.getElapsedTime();

        ///esta es la otra wea que revisa las colisiones hacia los soldados...

        if(elapsed2.asSeconds() >= 0.5){

        clock2.restart();
            counter = 0;
            for(IteradorE = EnemyArray.begin(); IteradorE != EnemyArray.end(); IteradorE++){

                if( soldado.RECT.getGlobalBounds().intersects(EnemyArray[counter].RECT.getGlobalBounds())){

                    TextDISPLAY1.TEXT.setString(to_string(EnemyArray[counter].ATK));
                    TextDISPLAY1.TEXT.setPosition(soldado.RECT.getPosition().x, soldado.RECT.getPosition().y);
                    TextArray.push_back(TextDISPLAY1);

                    soldado.HP -= EnemyArray[counter].ATK;
                }
                counter++;

            }
        }
        cout << soldado.HP << endl;



        ///esta es la wea que revisa las colisiones hacia los enemigos...
        counter = 0;
        for(Iterador = projectileArray.begin(); Iterador != projectileArray.end(); Iterador++){

            counter2 = 0;
            for(IteradorE = EnemyArray.begin(); IteradorE != EnemyArray.end(); IteradorE++){

                if(projectileArray[counter].RECT.getGlobalBounds().intersects(EnemyArray[counter2].RECT.getGlobalBounds())){

                    cout << "Colisiones putito...!" << endl;
                    projectileArray[counter].Destroy = true;

                    ///se setea el damage que recibe el enemigo por parte del soldier...
                    TextDISPLAY1.TEXT.setString(to_string(projectileArray[counter].ATK));
                    TextDISPLAY1.TEXT.setPosition(EnemyArray[counter2].RECT.getPosition().x, EnemyArray[counter2].RECT.getPosition().y);
                    TextArray.push_back(TextDISPLAY1);
                    ///aqui empieza otra madre (reduccion de hp del enemigo)
                    EnemyArray[counter2].HP -= projectileArray[counter].ATK;
                    if(EnemyArray[counter2].HP <= 0){

                        EnemyArray[counter2].Vivo = false;
                    }

                }

                counter2++;
            }
            counter++;
        }

        ///Esta madre se fuma a los cerdos muertos...
        counter = 0;
        for(IteradorE = EnemyArray.begin(); IteradorE != EnemyArray.end(); IteradorE++){

            if(EnemyArray[counter].Vivo == false){

                cout << "Un enemigo ha caido...!!!" << endl;
                EnemyArray.erase(IteradorE);
                break;
            }
            counter++;
        }
        ///Esta otra gonorrea se fuma los proyectiles...
        counter = 0;
        for(Iterador = projectileArray.begin(); Iterador != projectileArray.end(); Iterador++){

            if(projectileArray[counter].Destroy == true){

                projectileArray.erase(Iterador);
                break;
            }

            counter++;
        }
        ///Esta vara se fuma los textos de los enemigos ( damage deal)
        counter = 0;
        for(IteradorT = TextArray.begin(); IteradorT != TextArray.end(); IteradorT++){

            if(TextArray[counter].Destroy == true){

                TextArray.erase(IteradorT);
                break;
            }
            counter++;
        }




        //Esta wea es para setear lo del poder 1
        if(elapsed1.asSeconds() >= 0.1){

            clock1.restart();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
            {
            soundFireBall.play();
            Power1.RECT.setPosition(soldado.RECT.getPosition().x + soldado.RECT.getSize().x/2 - Power1.RECT.getSize().x/2,
                soldado.RECT.getPosition().y + soldado.RECT.getSize().y/2 - Power1.RECT.getSize().y/2);
            Power1.direction = soldado.direction;
            projectileArray.push_back(Power1);
            }
        }

        //esta madre es para setear lo del poder 2
        if(elapsed1.asSeconds() >= 0.1){

            clock1.restart();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
            {
            soundFireBall.play();
            Power1.RECT.setPosition(soldado.RECT.getPosition().x + soldado.RECT.getSize().x/2 - Power1.RECT.getSize().x/2,
                soldado.RECT.getPosition().y + soldado.RECT.getSize().y/2 - Power1.RECT.getSize().y/2);
            Power1.direction = 1;
            projectileArray.push_back(Power1);

            Power1.RECT.setPosition(soldado.RECT.getPosition().x + soldado.RECT.getSize().x/2 - Power1.RECT.getSize().x/2,
                soldado.RECT.getPosition().y + soldado.RECT.getSize().y/2 - Power1.RECT.getSize().y/2);
            Power1.direction = 2;
            projectileArray.push_back(Power1);

            Power1.RECT.setPosition(soldado.RECT.getPosition().x + soldado.RECT.getSize().x/2 - Power1.RECT.getSize().x/2,
                soldado.RECT.getPosition().y + soldado.RECT.getSize().y/2 - Power1.RECT.getSize().y/2);
            Power1.direction = 3;
            projectileArray.push_back(Power1);

            Power1.RECT.setPosition(soldado.RECT.getPosition().x + soldado.RECT.getSize().x/2 - Power1.RECT.getSize().x/2,
                soldado.RECT.getPosition().y + soldado.RECT.getSize().y/2 - Power1.RECT.getSize().y/2);
            Power1.direction = 4;
            projectileArray.push_back(Power1);

            }
        }



        //dibujo las bolas de fuego
        counter = 0;
        for(Iterador = projectileArray.begin(); Iterador != projectileArray.end(); Iterador++){

            projectileArray[counter].Update();
            //Window.draw(projectileArray[counter].RECT);
            Window.draw(projectileArray[counter].SPRITE);
            counter++;
        }
        //IteradorE = EnemyArray.begin(); IteradorE != EnemyArray.end(); IteradorE++
        counter1 = 0;
        for(IteradorE = EnemyArray.begin(); IteradorE != EnemyArray.end(); IteradorE++){

            EnemyArray[counter1].UpDate();
            EnemyArray[counter1].UpDateMovement();
            Window.draw(EnemyArray[counter1].SPRITE);
            counter1++;
        }

        soldado.UpDate();
        soldado.UpDateMovement();
        Window.draw(soldado.SPRITE);


       // Enemigo.UpDate();
       // Enemigo.UpDateMovement();
        //Window.draw(Enemigo.SPRITE);

        //Enemigo2.UpDate();
        //Window.draw(Enemigo2.SPRITE);

        Window.draw(Enemytest);
        Window.draw(gemtest);

        counter = 0;
        for(IteradorT = TextArray.begin(); IteradorT != TextArray.end(); IteradorT++){

            TextArray[counter].UpDate();
            Window.draw(TextArray[counter].TEXT);
            counter++;
        }


        Window.display();
    }



    return 0;
}
