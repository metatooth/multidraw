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

#ifndef LIBMULTIDRAW_COMPONENT_NAME_VAR_HPP
#define LIBMULTIDRAW_COMPONENT_NAME_VAR_HPP

#include <libmultidraw/state_vars/NameVar.hpp>

#include <string>

namespace multidraw {

  class Component;
  
  /**
   * A name for a component.
   */
  class ComponentNameVar : public NameVar {
  public:
    ComponentNameVar(Component*);

    Component* component() const;
    void component(Component*);
    void update();
  
  private:
    Component* _component;
  };

}

#endif // LIBMULTIDRAW_COMPONENT_NAME_VAR_HPP
