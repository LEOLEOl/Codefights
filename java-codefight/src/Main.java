import javafx.collections.transformation.SortedList;

import java.util.*;

/**
 * Created by LEOLEOl on 9/3/2017.
 */
public class Main {
    public static void main(String[] args) {
        // System.out.println("Hello World");
        groupingDishes(dishes);
    }

    protected static String[][] dishes = {{"Pasta", "Tomato Sauce", "Onions", "Garlic"},
            {"Chicken Curry", "Chicken", "Curry Sauce"},
            {"Fried Rice", "Rice", "Onions", "Nuts"},
            {"Salad", "Spinach", "Nuts"},
            {"Sandwich", "Cheese", "Bread"},
            {"Quesadilla", "Chicken", "Cheese"}};

    public static String[][] getString2DFromMap(TreeMap<String, TreeSet<String>> map) {
        String[][] ret = new String[map.size()][];

        int i = 0;
        for (Map.Entry<String, TreeSet<String>> entry : map.entrySet()) {
            ret[i] = new String[entry.getValue().size() + 1];
            ret[i][0] = entry.getKey();
            int j = 1;
            for (String s : entry.getValue()) {
                ret[i][j] = s;
                ++j;
            }
            ++i;
        }
        return ret;
    }

    public static String[][] groupingDishes(String[][] dishes) {
        TreeMap<String, TreeSet<String>> mapResult = new TreeMap<>(); // to store the return value
        Map<String, String> mapSet = new HashMap<>(); // to store the first element.
        for (int i = 0; i < dishes.length; ++i) {
            for (int j = 1; j < dishes[i].length; ++j) {
                if (!mapSet.containsKey(dishes[i][j])) {
                    mapSet.put(dishes[i][j], dishes[i][0]);
                }
                else {
                    TreeSet value;
                    if (mapResult.get(dishes[i][j]) == null) {
                        value = new TreeSet();
                        value.add(mapSet.get(dishes[i][j]));
                        value.add(dishes[i][0]);
                        mapResult.put(dishes[i][j], value);
                    }
                    else {
                        value = mapResult.get(dishes[i][j]);
                        value.add(dishes[i][0]);
                        mapResult.put(dishes[i][j], value);
                    }
                }
            }
        }
        return getString2DFromMap(mapResult);
    }
}
