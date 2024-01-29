    int y;
    for (int i = 0; i < 1; i++){
        for (int j = 0; j < 3; j++){
            std:: cin >> y;
            mtx(i,j) = y;
        }
    }
    matrix<int,1,3> mty;
    for (int i = 0; i < 1; i++){
        for (int j = 0; j < 3; j++){
            std:: cin >> y;
            mty(i,j) = y;
        }
    }
    matrix<int,1,3> mtz;
    mtz = mtx + mty;
    mtz.print();