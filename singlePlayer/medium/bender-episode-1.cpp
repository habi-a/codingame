#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Map
{
public:
    // Constructor / Destructor
    Map(vector<string> &carte) : _carte(carte)
    {
        _isTeleporteur = false;
        for (unsigned int i = 0; i < _carte.size(); i++)
            for (unsigned int j = 0; j < _carte.size(); j++)
            {
                if (_carte[i][j] == '@')
                {
                    _xBender = j;
                    _yBender = i;
                }
                else if (_carte[i][j] == 'T' && !_isTeleporteur)
                {
                    _xFirstTeleporteur = j;
                    _yFirstTeleporteur = i;
                    _isTeleporteur = true;
                }
                else if (_carte[i][j] == 'T')
                {
                    _xSecondTeleporteur = j;
                    _ySecondTeleporteur = i;
                }
            }
    };
    ~Map() {};

    // Getter
    unsigned int const& getXBender() const { return _xBender; };
    unsigned int const& getYBender() const { return _yBender; };
    unsigned int const& getXFirstTeleporteur() const { return _xFirstTeleporteur; };
    unsigned int const& getYFirstTeleporteur() const { return _yFirstTeleporteur; };
    unsigned int const& getXSecondTeleporteur() const { return _xSecondTeleporteur; };
    unsigned int const& getYSecondTeleporteur() const { return _ySecondTeleporteur; };
    char const& getCell(const unsigned int x, const unsigned int y) const { return _carte[y][x]; };
    bool isObstacle(const unsigned int x, const unsigned int y) const { return (_carte[y][x] == 'X'); };
    bool isWall(const unsigned int x, const unsigned int y) const { return (_carte[y][x] == '#'); };
    bool isBiere(const unsigned int x, const unsigned int y) const { return (_carte[y][x] == 'B'); };
    bool isTeleporteur(const unsigned int x, const unsigned int y) const { return (_carte[y][x] == 'T'); };
    bool isInversor(const unsigned int x, const unsigned int y) const { return (_carte[y][x] == 'I'); };
    bool isChangeDirection(const unsigned int x, const unsigned int y) const { return (_carte[y][x] == 'N' || _carte[y][x] == 'S' || _carte[y][x] == 'E' || _carte[y][x] == 'W'); };

    // Setter
    void removeCell(const unsigned int x, const unsigned y) { _carte[y][x] = '_'; };

private:
    bool            _isTeleporteur;
    unsigned int    _xBender;
    unsigned int    _yBender;
    unsigned int    _xFirstTeleporteur;
    unsigned int    _yFirstTeleporteur;
    unsigned int    _xSecondTeleporteur;
    unsigned int    _ySecondTeleporteur;
    vector<string>  &_carte;
};


class Bender
{
public:
    // Constructor / Destructor
    Bender(Map &map) : _map(map)
    {
        _x = _map.getXBender();
        _y = _map.getYBender();
        _direction = "SOUTH";
        _casseur = false;
        _priorities = {"SOUTH", "EAST", "NORTH", "WEST"};
    };
    ~Bender() {};

    // Getter
    bool isCasseur() const { return _casseur; };
    bool isDead() const { return (_map.getCell(_x, _y) == '$'); };
    unsigned int const& getX() const { return _x; };
    unsigned int const& getY() const { return _y; };
    string const& getDirection() const { return _direction; };

    // Setter
    void setX(const unsigned int x) { _x = x; };
    void setY(const unsigned int y) { _y = y; };
    void setDirection(string const& direction) {_direction = direction; };
    void switchCasseurMode()
    {
        if (_casseur)
            _casseur = false;
        else
            _casseur = true;
    }
    void switchPriorities()
    {
        if (_priorities[0] == "SOUTH")
        {
            _priorities.clear();
            _priorities = {"WEST", "NORTH", "EAST", "SOUTH"};
        }
        else
        {
            _priorities.clear();
            _priorities = {"SOUTH", "EAST", "NORTH", "WEST"};
        }
    };
    string const chooseDirection()
    {
        if (checkMove(_direction))
            return _direction;
        for (auto direction : _priorities)
        {
            if (checkMove(direction))
            {
                _direction = direction;
                return direction;
                cerr << "here ?" << endl;
            }
        }
        return "LOOP";
    };
    bool checkMove(string direction)
    {
        bool isWalkable = true;
        auto x = _x;
        auto y = _y;

        if (direction == "NORTH")
            y--;
        else if(direction == "SOUTH")
            y++;
        else if(direction == "WEST")
            x--;
        else
            x++;

        if (_map.isObstacle(x, y) && !_casseur)
            isWalkable = false;
        else if (_map.isWall(x, y))
            isWalkable = false;

        return isWalkable;
    };
    void move()
    {
        if (_direction == "NORTH")
            _y--;
        else if(_direction == "SOUTH")
            _y++;
        else if(_direction == "WEST")
            _x--;
        else
            _x++;

        if (_map.isInversor(_x, _y))
            switchPriorities();
        else if (_map.isBiere(_x, _y))
            switchCasseurMode();
        else if (_map.isChangeDirection(_x, _y))
        {
            switch(_map.getCell(_x, _y))
            {
                case 'N':
                    setDirection("NORTH");
                    break;

                case 'S':
                    setDirection("SOUTH");
                    break;

                case 'E':
                    setDirection("EAST");
                    break;

                case 'W':
                    setDirection("WEST");
                    break;
            }
        }
        else if (_map.isTeleporteur(_x, _y))
        {
            if (_x == _map.getXFirstTeleporteur() && _y == _map.getYFirstTeleporteur())
            {
                _x = _map.getXSecondTeleporteur();
                _y = _map.getYSecondTeleporteur();
            }
            else
            {
                _x = _map.getXFirstTeleporteur();
                _y = _map.getYFirstTeleporteur();
            }
        }
        else if (_map.isObstacle(_x, _y) && _casseur)
            _map.removeCell(_x, _y);
    };

private:
    Map             &_map;
    bool            _casseur;
    unsigned int    _x;
    unsigned int    _y;
    string          _direction;
    vector<string>  _priorities;
};

int                 main()
{
    int             L;
    int             C;
    unsigned int    compteur = 0;
    vector<string>  carte;
    vector<string>  results;

    cin >> L >> C; cin.ignore();

    for (int i = 0; i < L; i++)
    {
        string row;
        getline(cin, row);
        carte.push_back(row);
    }
    Map map(carte);
    Bender bender(map);

    while(!bender.isDead())
    {
        results.push_back(bender.chooseDirection());
        bender.move();
        compteur++;
        if (compteur == 20000)
        {
            results.clear();
            results.push_back("LOOP");
            break;
        }
    }

    for (auto direction : results)
    cout << direction << endl;
    return 0;
}
