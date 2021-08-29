#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

#include <memory>
#include <vector>
#include <string>
#include "chatbot.h"


class GraphEdge;

class GraphNode
{
private:
    std::vector<std::unique_ptr<GraphEdge>> _childEdges;
    std::vector<GraphEdge *> _parentEdges;
    ChatBot _chatBot;
    int _id;
    std::vector<std::string> _answers;

public:
    GraphNode(int id);
    ~GraphNode();
    int GetID() { return _id; }
    int GetNumberOfChildEdges() { return _childEdges.size(); }
    GraphEdge *GetChildEdgeAtIndex(int index);
    std::vector<std::string> GetAnswers() { return _answers; }
    int GetNumberOfParents() { return _parentEdges.size(); }
    void AddToken(std::string token); 
    void AddEdgeToParentNode(GraphEdge *edge);
    void AddEdgeToChildNode(std::unique_ptr<GraphEdge> &edge);
    void MoveChatbotHere(ChatBot chatbot);
    void MoveChatbotToNewNode(GraphNode *newNode);
};

#endif