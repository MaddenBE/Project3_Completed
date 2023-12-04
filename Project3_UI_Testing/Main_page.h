#pragma once
#include "IncludeStatements.h"
#include "DataComparison.h"
#define file "MovieData.txt"
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
using namespace std;

class Main_Page{
public:
    string initialize() {
        sf::RenderWindow mainwindow(sf::VideoMode(700, 700), "main", sf::Style::Close);
        DataComparison structures(file);
        pair<long, vector<Movie>> results;
        char searching[100] = {};
        searching[0] = '|';
        bool clicked = true;
        int i = 0;
        sf::Text name;
        sf::Text InputPrompt;
        sf::Text Input;
        sf::Text search_type;
        sf::Text result1;
        sf::Text result2;
        sf::Text result3;
        sf::Text result4;
        sf::Text result5;
        sf::Text time_result;
        sf::Font font;
        font.loadFromFile("files/AidaSerifa-Condensed.ttf");

        name.setFont(font);
        name.setCharacterSize(24);
        name.setFillColor(sf::Color::Black);
        name.setStyle(sf::Text::Underlined);
        name.setString("Movie Finder");
        sf::FloatRect namerect = name.getLocalBounds();
        name.setOrigin(namerect.left + namerect.width / 2.0f, namerect.top + namerect.height / 2.0f + 200);
        name.setPosition(sf::Vector2f(mainwindow.getSize().x / 2.0f, mainwindow.getSize().y / 2.0f));

        InputPrompt.setFont(font);
        InputPrompt.setFont(font);
        InputPrompt.setCharacterSize(20);
        InputPrompt.setFillColor(sf::Color::Black);
        InputPrompt.setStyle(sf::Text::Bold);
        InputPrompt.setString("Enter movie name: ");
        sf::FloatRect inputrect = InputPrompt.getLocalBounds();
        InputPrompt.setOrigin(inputrect.left + inputrect.width / 2.0f, inputrect.top + inputrect.height / 2.0f + 75);
        InputPrompt.setPosition(sf::Vector2f(mainwindow.getSize().x / 2.0f, mainwindow.getSize().y / 2.0f));

        Input.setFont(font);
        Input.setCharacterSize(18);
        Input.setFillColor(sf::Color::Black);
        Input.setStyle(sf::Text::Bold);
        Input.setString(searching);
        sf::FloatRect txtrect = InputPrompt.getLocalBounds();
        Input.setOrigin(txtrect.left + txtrect.width / 2.0f, txtrect.top + txtrect.height / 2.0f + 45);
        Input.setPosition(sf::Vector2f(mainwindow.getSize().x / 2.0f, mainwindow.getSize().y / 2.0f));

        search_type.setFont(font);
        search_type.setCharacterSize(18);
        search_type.setFillColor(sf::Color::Black);
        search_type.setStyle(sf::Text::Bold);
        search_type.setString("Search Type: Map");
        sf::FloatRect searchrect = search_type.getLocalBounds();
        search_type.setOrigin(searchrect.left + searchrect.width/2.0f - 200, searchrect.top +searchrect.height / 2.0f +75);
        search_type.setPosition(sf::Vector2f(mainwindow.getSize().x / 2.0f, mainwindow.getSize().y / 2.0f));

        result1.setFont(font);
        result1.setCharacterSize(18);
        result1.setFillColor(sf::Color::Black);
        result1.setStyle(sf::Text::Bold);
        result1.setString("");
        sf::FloatRect result1rect = result1.getLocalBounds();
        result1.setOrigin(result1rect.left + result1rect.width/2.0f + 300, result1rect.top + result1rect.height / 2.0f - 45);
        result1.setPosition(sf::Vector2f(mainwindow.getSize().x / 2.0f, mainwindow.getSize().y / 2.0f));

        result2.setFont(font);
        result2.setCharacterSize(18);
        result2.setFillColor(sf::Color::Black);
        result2.setStyle(sf::Text::Bold);
        result2.setString("");
        sf::FloatRect result2rect = result2.getLocalBounds();
        result2.setOrigin(result2rect.left + result2rect.width/2.0f + 300, result2rect.top + result2rect.height / 2.0f - 65);
        result2.setPosition(sf::Vector2f(mainwindow.getSize().x / 2.0f, mainwindow.getSize().y / 2.0f));


        result3.setFont(font);
        result3.setCharacterSize(18);
        result3.setFillColor(sf::Color::Black);
        result3.setStyle(sf::Text::Bold);
        result3.setString("");
        sf::FloatRect result3rect = result3.getLocalBounds();
        result3.setOrigin(result3rect.left + result3rect.width/2.0f + 300, result3rect.top + result3rect.height / 2.0f - 85);
        result3.setPosition(sf::Vector2f(mainwindow.getSize().x / 2.0f, mainwindow.getSize().y / 2.0f));


        result4.setFont(font);
        result4.setCharacterSize(18);
        result4.setFillColor(sf::Color::Black);
        result4.setStyle(sf::Text::Bold);
        result4.setString("");
        sf::FloatRect result4rect = result4.getLocalBounds();
        result4.setOrigin(result4rect.left + result4rect.width/2.0f + 300, result4rect.top + result4rect.height / 2.0f - 105);
        result4.setPosition(sf::Vector2f(mainwindow.getSize().x / 2.0f, mainwindow.getSize().y / 2.0f));


        result5.setFont(font);
        result5.setCharacterSize(18);
        result5.setFillColor(sf::Color::Black);
        result5.setStyle(sf::Text::Bold);
        result5.setString("");
        sf::FloatRect result5rect = result5.getLocalBounds();
        result5.setOrigin(result5rect.left + result5rect.width/2.0f + 300, result5rect.top + result5rect.height / 2.0f - 125);
        result5.setPosition(sf::Vector2f(mainwindow.getSize().x / 2.0f, mainwindow.getSize().y / 2.0f));

        time_result.setFont(font);
        time_result.setCharacterSize(18);
        time_result.setFillColor(sf::Color::Black);
        time_result.setStyle(sf::Text::Bold);
        time_result.setString("");
        sf::FloatRect timerect = time_result.getLocalBounds();
        time_result.setOrigin(timerect.left + timerect.width/2.0f + 300, timerect.top + timerect.height / 2.0f - 175);
        time_result.setPosition(sf::Vector2f(mainwindow.getSize().x / 2.0f, mainwindow.getSize().y / 2.0f));


        while (mainwindow.isOpen()) {
            mainwindow.clear(sf::Color(255, 255, 255, 255));
            sf::Event event{};
            while (mainwindow.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    mainwindow.close();
                    return "|";
                }
                else if(event.type == sf::Event::MouseButtonPressed){
                    if(event.mouseButton.button == sf::Mouse::Left){
                        auto mouse_position = sf::Mouse::getPosition(mainwindow);
                        auto position = mainwindow.mapPixelToCoords(mouse_position);
                        if (search_type.getGlobalBounds().contains(position)){
                            if(clicked == true){
                                search_type.setString("Search Type: Map");
                                clicked = false;
                            }
                            else{
                                search_type.setString("Search Type: Trie");
                                clicked = true;
                            }
                        }

                    }
                }
                else if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Enter && searching[0] != '|'){
                        mainwindow.close();
                    searching[i] = {};
                    string search_key = searching;
                    return search_key;
                    }
                    else if(event.key.code == sf::Keyboard::Space){
                        searching[i] = {' '};
                        i++;
                        if (i > 97) {
                            continue;
                        } else if (i != 98) {
                            searching[i] = '|';
                        }
                        Input.setString(searching);
                    }
                    else if (0 <= event.key.code && event.key.code <= 25 && i <= 97) {
                        searching[i] = ('a' + event.key.code);
                        if (i == 0) {
                            searching[i] = tolower(searching[i]);
                        }
                        string key = searching;
                        if(clicked == false) {
                            results = (structures.search_in_trie(key, 5));
                            if (!results.second.empty()){
                                string title = results.second[0].title;
                                if (title.length() <= 100) {
                                    result1.setString(title);
                                } else {
                                    result1.setString(title.substr(0, 97) + "...");
                                }
                                if (results.second.size() > 1) {
                                    title = results.second[1].title;
                                    if (title.length() <= 100) {
                                        result2.setString(title);
                                    } else {
                                        result2.setString(title.substr(0, 97) + "...");
                                    }
                                } else {
                                    result2.setString("");
                                }
                                if (results.second.size() > 2) {
                                    title = results.second[2].title;
                                    if (title.length() <= 100) {
                                        result3.setString(title);
                                    } else {
                                        result3.setString(title.substr(0, 97) + "...");
                                    }
                                } else {
                                    result3.setString("");
                                }
                                if (results.second.size() > 3) {
                                    title = results.second[3].title;
                                    if (title.length() <= 100) {
                                        result4.setString(title);
                                    } else {
                                        result4.setString(title.substr(0, 97) + "...");
                                    }
                                } else {
                                    result4.setString("");
                                }
                                if (results.second.size() > 4) {
                                    title = results.second[4].title;
                                    if (title.length() <= 100) {
                                        result5.setString(title);
                                    } else {
                                        result5.setString(title.substr(0, 97) + "...");
                                    }
                                } else {
                                    result5.setString("");
                                }
                                time_result.setString("Time: " + to_string(results.first) + " ns");
                            }

                        }
                        else{
                            results = (structures.search_in_map(key, 5));
                            if (!results.second.empty()){
                                string title = results.second[0].title;
                                if (title.length() <= 100) {
                                    result1.setString(title);
                                } else {
                                    result1.setString(title.substr(0, 97) + "...");
                                }
                                if (results.second.size() > 1) {
                                    title = results.second[1].title;
                                    if (title.length() <= 100) {
                                        result2.setString(title);
                                    } else {
                                        result2.setString(title.substr(0, 97) + "...");
                                    }
                                } else {
                                    result2.setString("");
                                }
                                if (results.second.size() > 2) {
                                    title = results.second[2].title;
                                    if (title.length() <= 100) {
                                        result3.setString(title);
                                    } else {
                                        result3.setString(title.substr(0, 97) + "...");
                                    }
                                } else {
                                    result3.setString("");
                                }
                                if (results.second.size() > 3) {
                                    title = results.second[3].title;
                                    if (title.length() <= 100) {
                                        result4.setString(title);
                                    } else {
                                        result4.setString(title.substr(0, 97) + "...");
                                    }
                                } else {
                                    result4.setString("");
                                }
                                if (results.second.size() > 4) {
                                    title = results.second[4].title;
                                    if (title.length() <= 100) {
                                        result5.setString(title);
                                    } else {
                                        result5.setString(title.substr(0, 97) + "...");
                                    }
                                } else {
                                    result5.setString("");
                                }
                                time_result.setString("Time: " + to_string(results.first) + " ns");
                            }

                        }
                        i++;
                        if (i > 97) {
                            continue;
                        } else if (i != 98) {
                            searching[i] = '|';
                        }
                        Input.setString(searching);




                    } else if (event.key.code == sf::Keyboard::BackSpace && i > 0) {
                        searching[i] = {};
                        i--;
                        searching[i] = '|';
                        result1.setString("");
                        result2.setString("");
                        result3.setString("");
                        result4.setString("");
                        result5.setString("");
                        time_result.setString("");
                        Input.setString(searching);
                    }
                }
            }
            mainwindow.draw(name);
            mainwindow.draw(InputPrompt);
            mainwindow.draw(Input);
            mainwindow.draw(search_type);
            mainwindow.draw(result1);
            mainwindow.draw(result2);
            mainwindow.draw(result3);
            mainwindow.draw(result4);
            mainwindow.draw(result5);
            mainwindow.draw(time_result);
            mainwindow.display();
        }


        return "|";
    }
};
