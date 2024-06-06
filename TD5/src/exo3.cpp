#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <unordered_map>

enum class CardKind {
    Heart,
    Diamond,
    Club,
    Spade,
};

enum class CardValue {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

struct Card {
    CardKind kind;
    CardValue value;

    int hash() const;
};

bool operator== (Card const& card_1, Card const& card_2){
    return (card_1.kind == card_2.kind) && (card_1.value == card_2.value);
}

int Card::hash() const{
    return static_cast<int>(this->value)+13*static_cast<int>(this->kind);
    /* Etant donné que pour chaque (4) type de cartes on a les 13 mêmes valeurs de cartes possibles, on sait que 13x4 = 52.
        Donc pour que chaque cartes aie sa propre valeur, on prend la valeur de la carte et on y additionne le pallier (type * 13) auquel il appartient.
        Ainsi, entre chaque type, il faut sauter de 13 cartes.
    */
}

namespace std {
    template<>
    struct hash<Card> {
        size_t operator()(Card const& card) const {
            return card.hash();
        }
    };
}

std::vector<Card> get_cards(size_t const size) {
    std::vector<Card> cards {};
    cards.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        cards.push_back({static_cast<CardKind>(rand() % 4), static_cast<CardValue>(rand() % 13)});
    }
    return cards;
}

std::string card_name(Card const& card) {
    std::string name {};

    unsigned int card_value {(static_cast<unsigned int>(card.value)+2) % 14};

    if (card_value < 10) {
        name += '0' + card_value;
    }else if (card_value == 10) {
        name += "10";
    }else if (card_value == 11) {
        name += 'V';
    }else if (card_value == 12) {
        name += 'Q';
    }else if (card_value == 13) {
        name += 'K';
    }

    name += " of ";

    if (card.kind == CardKind::Heart) {
        name += "Heart";
    }else if (card.kind == CardKind::Diamond) {
        name += "Diamond";
    }else if (card.kind == CardKind::Club) {
        name += "Club";
    }else if (card.kind == CardKind::Spade) {
        name += "Spade";
    }
    return name;
}

int main(){
    Card card_1 {CardKind::Heart, CardValue::Two};
    Card card_2 {CardKind::Heart, CardValue::Ace};
    // if(card_1==card_2){
    //     std::cout << "c'est égal." << std::endl;
    // }
    // else {
    //     std::cout << "PAS égal." << std::endl;
    // }
    std::cout << "hashage de la carte 2 de coeur : " << card_1.hash() << std::endl;
    std::cout << "hashage de la carte ace de coeur : " << card_2.hash() << std::endl;

    //Question 4
    std::cout << std::endl;
    std::vector<Card> liste_cartes {get_cards(100)};
    std::unordered_map<Card, int> nombre_carte_sur_paquet {};
    for(Card carte : liste_cartes){
        nombre_carte_sur_paquet[carte] ++;
    }
    for(auto carte : nombre_carte_sur_paquet){
        std::cout << "La carte " << card_name(carte.first) << " apparait " << carte.second << " fois sur le paquet de 100 cartes." << std::endl;
    }

    return 0;
}