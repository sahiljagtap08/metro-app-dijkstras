#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
#include <stack>
#include <list>

using namespace std;

class Graph
{
private:
    struct Vertex
    {
        unordered_map<string, int> nbrs;
    };

    unordered_map<string, Vertex> vtces;

public:
    Graph() {}

    int numVertex()
    {
        return vtces.size();
    }

    bool containsVertex(string vname)
    {
        return vtces.find(vname) != vtces.end();
    }

    void addVertex(string vname)
    {
        Vertex vtx;
        vtces[vname] = vtx;
    }

    void removeVertex(string vname)
    {
        Vertex vtx = vtces[vname];
        vector<string> keys;

        for (const auto &kv : vtx.nbrs)
        {
            keys.push_back(kv.first);
        }

        for (const string &key : keys)
        {
            Vertex &nbrVtx = vtces[key];
            nbrVtx.nbrs.erase(vname);
        }

        vtces.erase(vname);
    }

    int numEdges()
    {
        int count = 0;

        for (const auto &kv : vtces)
        {
            count += kv.second.nbrs.size();
        }

        return count / 2;
    }

    bool containsEdge(string vname1, string vname2)
    {
        if (!containsVertex(vname1) || !containsVertex(vname2))
        {
            return false;
        }

        Vertex &vtx1 = vtces[vname1];
        return vtx1.nbrs.find(vname2) != vtx1.nbrs.end();
    }

    void addEdge(string vname1, string vname2, int value)
    {
        if (!containsVertex(vname1) || !containsVertex(vname2) || containsEdge(vname1, vname2))
        {
            return;
        }

        vtces[vname1].nbrs[vname2] = value;
        vtces[vname2].nbrs[vname1] = value;
    }

    void removeEdge(string vname1, string vname2)
    {
        if (!containsVertex(vname1) || !containsVertex(vname2) || !containsEdge(vname1, vname2))
        {
            return;
        }

        vtces[vname1].nbrs.erase(vname2);
        vtces[vname2].nbrs.erase(vname1);
    }

    void displayMap()
    {
        cout << "\t DC Metro Map" << endl;
        cout << "\t------------------" << endl;
        cout << "----------------------------------------------------" << endl;
        for (const auto &kv : vtces)
        {
            string key = kv.first;
            Vertex vtx = kv.second;

            cout << key << " =>" << endl;

            for (const auto &nbr : vtx.nbrs)
            {
                string nbrName = nbr.first;
                int cost = nbr.second;

                cout << "\t" << nbrName << "\t";
                if (nbrName.length() < 16)
                    cout << "\t";
                if (nbrName.length() < 8)
                    cout << "\t";
                cout << cost << endl;
            }
        }
        cout << "\t------------------" << endl;
        cout << "---------------------------------------------------" << endl;
    }

    void displayStations()
    {
        cout << "\n***********************************************************************\n";
        int i = 1;
        for (const auto &kv : vtces)
        {
            string key = kv.first;
            cout << i << ". " << key << endl;
            i++;
        }
        cout << "\n***********************************************************************\n";
    }

    bool hasPath(string vname1, string vname2, unordered_map<string, bool> &processed)
    {
        if (containsEdge(vname1, vname2))
        {
            return true;
        }

        processed[vname1] = true;

        Vertex &vtx = vtces[vname1];
        for (const auto &nbr : vtx.nbrs)
        {
            string nbrName = nbr.first;
            if (!processed.count(nbrName) || !processed[nbrName])
            {
                if (hasPath(nbrName, vname2, processed))
                {
                    return true;
                }
            }
        }

        return false;
    }

    class DijkstraPair
    {
    public:
    string vname;
    string psf;
    int cost;

    DijkstraPair() : vname(""), psf(""), cost(INT_MAX) {} // Default constructor

    DijkstraPair(string vname, string psf, int cost)
        : vname(vname), psf(psf), cost(cost) {}

        bool operator>(const DijkstraPair &other) const
        {
            return cost > other.cost;
        }
    };

    int dijkstra(string src, string des, bool nan)
    {
        int val = 0;
        vector<string> ans;
        unordered_map<string, DijkstraPair> map;
       priority_queue<DijkstraPair, vector<DijkstraPair>, greater<DijkstraPair> > heap;


        for (const auto &kv : vtces)
        {
            string key = kv.first;
            DijkstraPair np(key, "", INT_MAX);

            if (key == src)
            {
                np.cost = 0;
                np.psf = key;
            }

            heap.push(np);
            map[key] = np;
        }

        while (!heap.empty())
        {
            DijkstraPair rp = heap.top();
            heap.pop();

            if (rp.vname == des)
            {
                val = rp.cost;
                break;
            }

            map.erase(rp.vname);
            ans.push_back(rp.vname);

            Vertex &v = vtces[rp.vname];
            for (const auto &nbr : v.nbrs)
            {
                string nbrName = nbr.first;
                if (map.count(nbrName))
                {
                    int oc = map[nbrName].cost;
                    int nc;

                    if (nan)
                    {
                        Vertex &k = vtces[rp.vname];
                        nc = rp.cost + 120 + 40 * k.nbrs[nbrName];
                    }
                    else
                    {
                        nc = rp.cost + v.nbrs[nbrName];
                    }

                    if (nc < oc)
                    {
                        DijkstraPair &gp = map[nbrName];
                        gp.psf = rp.psf + nbrName;
                        gp.cost = nc;

                        heap.push(gp);
                    }
                }
            }
        }
    };
};
