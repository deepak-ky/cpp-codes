 while(indexToColor <= r) {
            color[indexToColor] = c;
            dsu.unite(indexToColor,indexToColor+1);
            indexToColor = dsu.findSuperParent(indexToColor);
        }