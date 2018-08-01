/*
* MIT License
*
* Copyright (c) 2018 Brennan Cain
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

#ifndef BSC_LIST_H
#define BSC_LIST_H
template<class T>
class List
{
  public:
    

    // look
    virtual T peek_front();
    virtual T peek_back();

    Virtual T at(int index);

    // add
    virtual bool push_front(T data);
    virtual bool push_back(T data);

    virtual bool insert(T data, int index);

    //remove
    virtual T pop_front();
    virtual T pop_back();

    virtual T remove(int index);

    // -1 if not in list
    virtual int contains(T data);

    virtual void shuffle();
    virtual void sort();

    //0 if empty
    virtual int size();
};
#endif
