/**
 * @file main.cpp
 * Contains code to test your Quadtree implementation.
 */

#include <iostream>
#include "png.h"
#include "quadtree.h"

using std::cout;
using std::endl;

int main()
{

  PNG imgIn, imgOut, cMas, cMasOut, lePup, lePupOut, lucky;

  // lePup.readFromFile("puppy.png");
  //
  // // test constructor, decompress
  // Quadtree pupTree(lePup, 64);
  // Quadtree * pup = new Quadtree();
  // pup = &pupTree;
  // Quadtree lePope;
  // lePope = pupTree;
  // // cout << "lePope.pruneSize(0) = "      << lePope.pruneSize(0) << endl;
  // // cout << "lePope.pruneSize(100) = "    << lePope.pruneSize(100) << endl;
  // // cout << "lePope.pruneSize(1000) = "   << lePope.pruneSize(1000) << endl;
  // // cout << "lePope.pruneSize(100000) = " << lePope.pruneSize(100000) << endl;
  // // cout << "lePope.idealPrune(1000) = "  << lePope.idealPrune(1000) << endl;
  // // cout << "lePope.idealPrune(10000) = " << lePope.idealPrune(10000) << endl;
  // // // cout << "lePope.idealPrune(0) = "     << lePope.idealPrune(0) << endl;
  // // cout << "lePope.idealPrune(100000) = "<< lePope.idealPrune(100000) << endl;
  // pup->clockwiseRotate();
  // lePupOut = pup->decompress();
  // lePupOut.writeToFile("puppyOut.png");
  //
  //
  // lucky = lePope.decompress();
  // lucky.writeToFile("lePup.png");
  //
  // cMas.readFromFile("cmas.png");
  // Quadtree cTree(cMas, 4);


  // Quadtree cOutTree(cTree);
  // cMasOut = cOutTree.decompress();
  // cMasOut.writeToFile("cMasOut.png");


    // PNG imgIn, imgOut;
    imgIn.readFromFile("in.png");

    // test constructor, decompress
    Quadtree halfTree(imgIn, 128);
    imgOut = halfTree.decompress();
    imgOut.writeToFile("outHalf.png");

    // now for the real tests
    Quadtree fullTree;
    fullTree.buildTree(imgIn, 256);

    cout << "MY FILE" << endl;

    // you may want to experiment with different commands in this section

    // test pruneSize and idealPrune (slow in valgrind, so you may want to
    // comment these out when doing most of your testing for memory leaks)
    cout << "fullTree.pruneSize(0) = "      << fullTree.pruneSize(0) << endl;
    cout << "fullTree.pruneSize(100) = "    << fullTree.pruneSize(100) << endl;
    cout << "fullTree.pruneSize(1000) = "   << fullTree.pruneSize(1000) << endl;
    cout << "fullTree.pruneSize(100000) = " << fullTree.pruneSize(100000) << endl;
    cout << "fullTree.idealPrune(1000) = "  << fullTree.idealPrune(1000) << endl;
    // cout << "checking the big one" << endl;
    cout << "fullTree.idealPrune(10000) = " << fullTree.idealPrune(10000) << endl;

    // Test some creation/deletion functions
    Quadtree fullTree2;
    fullTree2 = fullTree;
    imgOut = fullTree2.decompress();
    imgOut.writeToFile("outCopy.png");

    // test clockwiseRotate
    fullTree.clockwiseRotate();
    imgOut = fullTree.decompress();
    imgOut.writeToFile("outRotated.png");

    // test prune
    fullTree = fullTree2;
    fullTree.prune(1000);
    imgOut = fullTree.decompress();
    imgOut.writeToFile("outPruned.png");

    // test several functions in succession
    Quadtree fullTree3(fullTree2);
    fullTree3.clockwiseRotate();
    fullTree3.prune(10000);
    fullTree3.clockwiseRotate();
    fullTree3.clockwiseRotate();
    fullTree3.clockwiseRotate();
    imgOut = fullTree3.decompress();
    imgOut.writeToFile("outEtc.png");

    // ensure that printTree still works
    Quadtree tinyTree(imgIn, 32);
    cout << "Printing tinyTree:\n";
    tinyTree.prune(100);
    tinyTree.printTree();

    return 0;
}
