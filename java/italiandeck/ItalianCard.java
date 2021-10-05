package italiandeck;

import java.util.Arrays;

public class ItalianCard {

    public enum Type {GOLD, SWORDS, CUPS, CLUBS}

    public enum Value {
        ACE(1), TWO(2), THREE(3), FOUR(4), FIVE(5), SIX(6), SEVEN(7), KNAVE(8), KNIGHT(9), KING(10);

        int numericValue;

        Value(int value) {
            this.numericValue = value;
        }

        public static Value getByNumericValue(int value) {
            return Arrays.stream(Value.values()).filter(c -> c.numericValue==value).findFirst().orElse(Value.ACE);
        }
    }

    private Type type;
    private Value value;

    public ItalianCard(Type type, Value value) {
        this.type = type;
        this.value = value;
    }

    public Type getType() { return type; }

    public void setType(Type type) { this.type = type; }

    public Value getValue() { return value; }

    public void setValue(Value value) { this.value = value; }
}
