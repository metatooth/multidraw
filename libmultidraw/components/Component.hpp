/*
 * Copyright (c) 1990, 1991 Stanford University
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided
 * that the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the name of Stanford not be used in advertising or
 * publicity pertaining to distribution of the software without specific,
 * written prior permission.  Stanford makes no representations about
 * the suitability of this software for any purpose.  It is provided "as is"
 * without express or implied warranty.
 *
 * STANFORD DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS.
 * IN NO EVENT SHALL STANFORD BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION
 * WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef LIBMULTIDRAW_COMPONENT_HPP
#define LIBMULTIDRAW_COMPONENT_HPP

#include <vector>
#include <iostream>

namespace multidraw {
  
  class Command;
  class Tool;

  /**
   * @brief Component is the base-class for all domain models.
   *
   * Component is a participant in the TOOLED COMPOSITE design
   * pattern. If it's "thing" in the problem domain, than it is
   * represented by a Component-derived class.
   */
  class Component {
  public:
    /**
     * @param name
     * @brief Default constructor.
     */
    Component(const std::string& = "");
    virtual ~Component() {};

    /// Sub-classes to define the command(s) generated by a user interaction
    virtual Command* accept(Tool&);

    /// Sub-classes to define how to execute command(s)
    virtual void interpret(Command*) { };
    virtual void uninterpret(Command*) { };

    /// Add a child
    virtual void add_child(Component*);

    /// Has visibility
    virtual bool visible() const { return _visible; };
    virtual void visible(bool visible) { _visible = visible; };

    /// Getter & setter for name
    std::string name() const { return _name; };
    void name(const std::string& name) { _name = name; };

    /// how many chidren?
    size_t children_size() const { return _children.size(); };

    Component* child(size_t index) const;
    Component* child(const std::string&) const;
    
    void parent(Component* parent) { _parent = parent; };
    Component* parent() const { return _parent; }
    Component* root();

    virtual void draw2() const;
    virtual void draw3() const;
  
  protected:
    std::vector<Component*> _children;
    bool _visible;
  private:
    std::string _name;
    Component* _parent;

  };

}

#endif // LIBMULTIDRAW_COMPONENT_HPP
