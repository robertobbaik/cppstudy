   backtracking(4, 0, 0);

    for(auto const& v : temp)
    {
        for(int n : v)
        {
            cout << n << " ";
        }

        cout << endl;
    }