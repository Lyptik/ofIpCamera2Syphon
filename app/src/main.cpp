// =============================================================================
//
// Copyright (c) 2009-2013 Christopher Baker <http://christopherbaker.net>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// =============================================================================


#include "ofApp.h"

int main()
{
    #ifdef __APPLE__
    // This makes relative paths work in C++ in Xcode by changing directory to the Resources folder inside the .app bundle
    // ----------------------------------------------------------------------------
    char path[2048];
    CFBundleRef mainBundle = CFBundleGetMainBundle();
    CFURLRef resourcesURL = CFBundleCopyResourcesDirectoryURL(mainBundle);
    if (!CFURLGetFileSystemRepresentation(resourcesURL, TRUE, (UInt8 *)path, 2048))
    {
        std::cerr << "Error : couldn't get bundle path resources" << std::endl;
    }
    CFRelease(resourcesURL);
    
    
    //int result = chdir(path); // do not move path because we are still using openframeworks stuff
    string resourcePath = ofToString(path);
    resourcePath.append("/");
    std::cout << "Current Path: " << resourcePath << std::endl;
    ofSetDataPathRoot(resourcePath); // openframeworks way to append string
    #endif
	
    ofSetupOpenGL(320*3,240*3,OF_WINDOW);
	ofRunApp(new ofApp());
}
