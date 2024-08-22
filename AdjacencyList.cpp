#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
using namespace std;


class AdjacencyList
{
private:
    map<string, float> current_ranking;

    map<string, float> old_ranking;

    map<string, float> hyperlink_probability;

    map<string, vector<pair<string, float>>> graph;

    float node_count = 0.0f;

    set<string> node_unique;

    set<string> to; // we insert nodes that are being pointed to 

public: 
    AdjacencyList()
    {

    }                                        
    void insertion(string start, string end)  // this function was inspired by slide 56 on the Graph Terminology and Implementation Presentation.
    {
        // as the user is inserting the keys, it counts how many unique nodes are within the graph :
        if (node_unique.count(start) == 0)
        {
            node_unique.insert(start);
            node_count++;
        }
        if (node_unique.count(end) == 0)
        {
            node_unique.insert(end);
            node_count++;
        }
        if (to.count(end) == 0)
        {
            to.insert(end);
        }

        //Counting the outdegees coming from the "start" Vertice
        hyperlink_probability[start] += 1.00;

        //This helps us avoids any duplicates accumulating as the graphs grows, pairs of (from,outdegree) are all in the same place and not spread out through out the vector
        bool start_already_inserted = false;
        for (auto &edge : graph[end])
        {
            if (edge.first == start)
            {
                start_already_inserted = true;
                break;
            }
        }
        //inserts the "to" variable as the key and pairs the "end" and outdegrees together.This allows for all the information we need to be in the same place for the power iterations
        if (!start_already_inserted)
        {
            graph[end].push_back(make_pair(start, 1.0 / hyperlink_probability[start]));
        }
        if (graph.find(end) == graph.end())
        {
            graph[end] = {};
        }
    }
    void PageRank(int n)
    {
        //this for loop inserts the finish outdegrees("hyperlink_probability") accumulations within the graph and pairs with the edge.first("from")
        for (auto it = graph.begin(); it != graph.end(); ++it)
        {

            for (auto &edge : it->second)
            {
                edge.second = 1 / hyperlink_probability[edge.first];
            }
        }
        //where we put our product of after power iteration process  
        float accumulating_rank = 0.0f;
        std::set<std::string, float>::iterator rank_loop;

         // this starts the page rank matrix
        for (auto rank_loop = node_unique.begin(); rank_loop != node_unique.end(); ++rank_loop)
        {
            current_ranking[*rank_loop] = 1 / node_count;
        }

        std::map<std::string, float>::iterator it;
        //for loop set to run n times
        for (size_t i = 0; i < n - 1; i++)
        {
            //this sets  the old rank map to new rank map, after we get done using the old rank values to get the new rank values
            for (auto rank_loop = node_unique.begin(); rank_loop != node_unique.end(); ++rank_loop)
            {
                old_ranking[*rank_loop] = current_ranking[*rank_loop];
            }

        //runs through the map
            for (auto it = graph.begin(); it != graph.end(); ++it)
            {
                //sets the accumulating_rank to zero for each key in the graph 
                accumulating_rank = 0.0f;
        //runs through the vector of the graph key 
                for (auto &edge : it->second)
                {
        //power iteration: goes through each pair and gets the ".first" value from "old_ranking" and multiply it with its .second 
                    accumulating_rank += (static_cast<float>(old_ranking[edge.first]) * static_cast<float>(edge.second));
                }
        //sets the finished accumulating rank to value of the "it->first" inside the current_ranking
                current_ranking[it->first] = accumulating_rank; 

        //plans for edge cases when a node has nothing pointing to it, sets the rank automatically to zero
                for (auto rank_loop = node_unique.begin(); rank_loop != node_unique.end(); ++rank_loop)
                {
                    if (to.count(*rank_loop) == 0)
                    {
                        current_ranking[*rank_loop] = 0;
                    }
                }
            }
        }
        //sets the finished ranks to a certain decimal place 
        cout << fixed << setprecision(2);

        //prints every rank 
        for (auto it = current_ranking.begin(); it != current_ranking.end(); ++it)
        {
            std::cout << it->first << " " << it->second << std::endl;
        }
    }
};

int main()
{
    int no_of_lines, power_iterations;
    string from, to;
    //how many inputs followed by how many power_iterations
    cin >> no_of_lines;
    cin >> power_iterations;
    // Create a graph object
    AdjacencyList AL;
    for (int i = 0; i < no_of_lines; i++)
    {
        //starting node and end node 
        cin >> from;
        cin >> to;
        AL.insertion(from, to);
    }
    AL.PageRank(power_iterations);
}