#include <sstream>
#include <fstream>
#include <string>
#include <random>
#include <tuple>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>
#include <time.h>

#include <graphviz/gvc.h>
#include <graphviz/gvplugin.h>

extern gvplugin_library_t gvplugin_core_LTX_library;
extern gvplugin_library_t gvplugin_gd_LTX_library;
extern gvplugin_library_t gvplugin_dot_layout_LTX_library;
extern gvplugin_library_t gvplugin_neato_layout_LTX_library;

static std::string dot_output;
static std::string graph_output;

/*
 * a handy funtion to initialize commonly used graphviz libraries
 */
 
void gt_init_gvplugins(GVC_t *gvc){
   gvAddLibrary(gvc, &gvplugin_core_LTX_library);
   gvAddLibrary(gvc, &gvplugin_gd_LTX_library);
   gvAddLibrary(gvc, &gvplugin_dot_layout_LTX_library);
   gvAddLibrary(gvc, &gvplugin_neato_layout_LTX_library);
}

/*
 * core function of generating corresponding dot file
 */
inline 
void gt_gendot_core(std::istream& in){
    int vertex_count, edge_count;
    int u, v, w;

    in >> vertex_count >> edge_count;

    dot_output.clear();
    dot_output.append("digraph {\n");
    while (in >> u >> v >> w) {
        dot_output.append("\t");
        dot_output.append(std::to_string(u));
        dot_output.append("->");
        dot_output.append(std::to_string(v));
        dot_output.append("[label=");
        dot_output.append(std::to_string(w));
        dot_output.append(",color=blue];\n");
    }
    dot_output.append("}");
}

/*
 * generate dot file string from given string from memory
 */
const std::string& gt_gendot(const std::string& src){
    std::istringstream in(src);
    gt_gendot_core(in);
    return dot_output;
}

/*
 * generate dot file string from give input stream
 */
const std::string& gt_gendot(std::istream& in){
    gt_gendot_core(in);
    return dot_output;
}

/*
 * generate dot file string from given file name
 */
const std::string& gt_gendot_from_file(const std::string& src_file){
    std::ifstream in(src_file.c_str());
    gt_gendot_core(in);
    return dot_output;
}

const std::string& gt_gen_graph(int vertex_count, int edge_count, int weight_min, int weight_max) {
    graph_output.clear();

    std::mt19937 mt(time(NULL));
    std::uniform_int_distribution<> vdistrib(0, vertex_count-1);
    std::uniform_int_distribution<> wdistrib(weight_min, weight_max); 

    // stores pair of vertices that has an edge between each other
    //
    std::set<std::pair<int,int> > vpairs;
    std::vector<std::tuple<int, int, int> > edges;

    for (int i = 0; i < edge_count; ++ i){
        int u, v, w;
GENPAIR:
        while ((u = vdistrib(mt)) == vertex_count-1);
        while ((v = vdistrib(mt)) <= u);

        if (!vpairs.empty() && vpairs.find(std::make_pair(u, v)) != vpairs.end()) {
            goto GENPAIR;
        }
        else {
            vpairs.insert(std::make_pair(u, v));
        }

        w = wdistrib(mt);
        edges.push_back(std::make_tuple(u, v, w));
    }

    std::sort (edges.begin(), edges.end(), [&](std::tuple<int, int, int> x, std::tuple<int, int, int> y) {
            if (std::get<0>(x) < std::get<0>(y)) {
                return true;
            }
            else if (std::get<1>(x) < std::get<1>(y)) {
                return true;
            }
            else {
                return false;
            }
    });

    graph_output.append(std::to_string(vertex_count));
    graph_output.append(" ");
    graph_output.append(std::to_string(edge_count));
    graph_output.append(" ");

    std::for_each (edges.cbegin(), edges.cend(), [&](std::tuple<int, int, int> x) {
        graph_output.append(std::to_string(std::get<0>(x)));
        graph_output.append(" ");
        graph_output.append(std::to_string(std::get<1>(x)));
        graph_output.append(" ");
        graph_output.append(std::to_string(std::get<2>(x)));
        graph_output.append("\n");

    });
    return graph_output;
} 

