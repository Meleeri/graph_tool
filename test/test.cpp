/*
 * test gt_common usability
 *
int main(int argc, char **argv){
   //string dot_str = gt_gendot_from_file ("test.txt");
   
   if (argc != 5) {
       cout << "Usage: test [vertex_count] [edge_count] [weight_min] [weight_max]" << endl;
       exit (0);
   }

   const string& graph_str = gt_gen_graph(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
   const string& dot_str = gt_gendot (graph_str);

   ofstream graph_str_file("graph.txt");
   graph_str_file << graph_str;

   Agraph_t *G;
   GVC_t *gvc;

   gvc = gvContext ();
   gt_init_gvplugins(gvc);
   G = agmemread(dot_str.c_str());

   gvLayout (gvc, G, "dot");
   gvRenderFilename(gvc, G, "png", "graph.png");
   
   gvFreeLayout (gvc, G);
   agclose (G);
   gvFreeContext (gvc);

   return 0;
}
*/
