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

class Results_Page{
public:
    string result_initialize(string key, pair<long, vector<Movie>> results){
        sf::RenderWindow mainwindow(sf::VideoMode(700, 700), "Results, close to reopen search", sf::Style::Close);
        DataComparison structures(file);
        char searching[100] = {};
        results = (structures.search_in_map(key, 5));
        searching[0] = '|';
        bool clicked = true;
        sf::Text name;
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

        Input.setFont(font);
        Input.setCharacterSize(18);
        Input.setFillColor(sf::Color::Black);
        Input.setStyle(sf::Text::Bold);
        Input.setString("Title of Interest: " + key);
        sf::FloatRect txtrect = Input.getLocalBounds();
        Input.setOrigin(txtrect.left + txtrect.width / 2.0f, txtrect.top + txtrect.height / 2.0f + 150);
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
        result1.setString(results.second[0].title + " | " + results.second[0].genre + " | " + results.second[0].year);
        sf::FloatRect result1rect = result1.getLocalBounds();
        result1.setOrigin(result1rect.left + result1rect.width/2.0f, result1rect.top + result1rect.height / 2.0f);
        result1.setPosition(sf::Vector2f(mainwindow.getSize().x / 2.0f, mainwindow.getSize().y / 2.0f));

        result2.setFont(font);
        result2.setCharacterSize(18);
        result2.setFillColor(sf::Color::Black);
        result2.setStyle(sf::Text::Bold);
        if (results.second.size()> 1) {
            result2.setString(results.second[1].title + " | " + results.second[1].genre + " | " + results.second[1].year);
        }
        else {
            result2.setString(" ");
        }
        sf::FloatRect result2rect = result2.getLocalBounds();
        result2.setOrigin(result2rect.left + result2rect.width/2.0f, result2rect.top + result2rect.height / 2.0f - 20);
        result2.setPosition(sf::Vector2f(mainwindow.getSize().x / 2.0f, mainwindow.getSize().y / 2.0f));


        result3.setFont(font);
        result3.setCharacterSize(18);
        result3.setFillColor(sf::Color::Black);
        result3.setStyle(sf::Text::Bold);
        if (results.second.size()>2) {
            result3.setString(results.second[2].title + " | " + results.second[2].genre + " | " + results.second[2].year);
        }
        else{
            result3.setString(" ");
        }
        sf::FloatRect result3rect = result3.getLocalBounds();
        result3.setOrigin(result3rect.left + result3rect.width/2.0f, result3rect.top + result3rect.height / 2.0f - 40);
        result3.setPosition(sf::Vector2f(mainwindow.getSize().x / 2.0f, mainwindow.getSize().y / 2.0f));


        result4.setFont(font);
        result4.setCharacterSize(18);
        result4.setFillColor(sf::Color::Black);
        result4.setStyle(sf::Text::Bold);
        if(results.second.size() > 3) {
            result4.setString(results.second[3].title + " | " + results.second[3].genre + " | " + results.second[3].year);
        }
        else{
            result4.setString(" ");
        }
        sf::FloatRect result4rect = result4.getLocalBounds();
        result4.setOrigin(result4rect.left + result4rect.width/2.0f, result4rect.top + result4rect.height / 2.0f - 60);
        result4.setPosition(sf::Vector2f(mainwindow.getSize().x / 2.0f, mainwindow.getSize().y / 2.0f));


        result5.setFont(font);
        result5.setCharacterSize(18);
        result5.setFillColor(sf::Color::Black);
        result5.setStyle(sf::Text::Bold);
        if (results.second.size() > 4) {
            result5.setString(results.second[4].title + " | " + results.second[4].genre + " | " + results.second[4].year);
        }
        else{
            result5.setString(" ");
        }
        sf::FloatRect result5rect = result5.getLocalBounds();
        result5.setOrigin(result5rect.left + result5rect.width/2.0f, result5rect.top + result5rect.height / 2.0f - 80);
        result5.setPosition(sf::Vector2f(mainwindow.getSize().x / 2.0f, mainwindow.getSize().y / 2.0f));

        time_result.setFont(font);
        time_result.setCharacterSize(18);
        time_result.setFillColor(sf::Color::Black);
        time_result.setStyle(sf::Text::Bold);
        time_result.setString("");
        sf::FloatRect timerect = time_result.getLocalBounds();
        time_result.setOrigin(timerect.left + timerect.width/2.0f, timerect.top + timerect.height / 2.0f - 120);
        time_result.setPosition(sf::Vector2f(mainwindow.getSize().x / 2.0f, mainwindow.getSize().y / 2.0f));


        while(mainwindow.isOpen()){
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
                                search_type.setString("Search Type: Trie");
                                results = (structures.search_in_trie(key, 5));
                                string title = results.second[0].title;
                                if (title.length() <= 100) {
                                    result1.setString(results.second[0].title + " | " + results.second[0].genre + " | " + results.second[0].year);
                                }
                                if (results.second.size() > 1) {
                                    title = results.second[1].title;
                                    if (title.length() <= 100) {
                                        result2.setString(results.second[1].title + " | " + results.second[1].genre + " | " + results.second[1].year);
                                    }
                                }
                                if (results.second.size() > 2) {
                                    title = results.second[2].title;
                                    if (title.length() <= 100) {
                                        result3.setString(results.second[2].title + " | " + results.second[2].genre + " | " + results.second[2].year);
                                    }
                                }
                                if (results.second.size() > 3) {
                                    title = results.second[3].title;
                                    if (title.length() <= 100) {
                                        result4.setString(results.second[3].title + " | " + results.second[3].genre + " | " + results.second[3].year);
                                    }
                                }
                                if (results.second.size() > 4) {
                                    title = results.second[4].title;
                                    if (title.length() <= 100) {
                                        result5.setString(results.second[4].title + " | " + results.second[4].genre + " | " + results.second[4].year);
                                    }
                                }
                                time_result.setString("Time: " + to_string(results.first) + " ns");
                                clicked = false;
                            }
                            else{
                                search_type.setString("Search Type: Map");
                                results = (structures.search_in_map(key, 5));
                                string title = results.second[0].title;
                                if (title.length() <= 100) {
                                    result1.setString(results.second[0].title + " | " + results.second[0].genre + " | " + results.second[0].year);
                                }
                                if (results.second.size() > 1) {
                                    title = results.second[1].title;
                                    if (title.length() <= 100) {
                                        result2.setString(results.second[1].title + " | " + results.second[1].genre + " | " + results.second[1].year);
                                    }
                                }
                                if (results.second.size() > 2) {
                                    title = results.second[2].title;
                                    if (title.length() <= 100) {
                                        result3.setString(results.second[2].title + " | " + results.second[2].genre + " | " + results.second[2].year);
                                    }
                                }
                                if (results.second.size() > 3) {
                                    title = results.second[3].title;
                                    if (title.length() <= 100) {
                                        result4.setString(results.second[3].title + " | " + results.second[3].genre + " | " + results.second[3].year);
                                    }
                                }
                                if (results.second.size() > 4) {
                                    title = results.second[4].title;
                                    if (title.length() <= 100) {
                                        result5.setString(results.second[4].title + " | " + results.second[4].genre + " | " + results.second[4].year);
                                    }
                                }
                                time_result.setString("Time: " + to_string(results.first) + " ns");
                                clicked = true;
                            }
                        }

                    }
                }
            }

            mainwindow.draw(name);
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
