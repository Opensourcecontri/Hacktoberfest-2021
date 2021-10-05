package italiandeck;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import static italiandeck.ItalianCard.Type.*;

public class ItalianDeck {

    public List<ItalianCard> cards;

    public ItalianDeck() {
        cards = new ArrayList<>();
        initializeDeck();
        shuffleDeck();
    }

    public void initializeDeck() {
        cards.clear();
        addType(GOLD);
        addType(CLUBS);
        addType(SWORDS);
        addType(CUPS);
    }

    public void shuffleDeck() {
        Collections.shuffle(cards);
    }

    private void addType(ItalianCard.Type t) {
        for (int i=1; i<=10; i++) {
            cards.add(new ItalianCard(t, ItalianCard.Value.getByNumericValue(i)));
        }
    }

}
