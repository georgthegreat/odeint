/*
 [auto_generated]
 boost/numeric/odeint/util/state_wrapper.hpp

 [begin_description]
 State wrapper for the state type in all stepper. The state wrappers are responsible for contruction,
 destruction, copying contruction, assignment and resizing.
 [end_description]

 Copyright 2009-2011 Karsten Ahnert
 Copyright 2009-2011 Mario Mulansky

 Distributed under the Boost Software License, Version 1.0.
 (See accompanying file LICENSE_1_0.txt or
 copy at http://www.boost.org/LICENSE_1_0.txt)
 */


#ifndef BOOST_NUMERIC_ODEINT_UTIL_STATE_WRAPPER_HPP_INCLUDED
#define BOOST_NUMERIC_ODEINT_UTIL_STATE_WRAPPER_HPP_INCLUDED


#include <boost/numeric/odeint/algebra/range_algebra.hpp>
#include <boost/type_traits/integral_constant.hpp>

#include <boost/numeric/odeint/util/is_resizeable.hpp>

namespace boost {
namespace numeric {
namespace odeint {

template< class V , typename resizeable = typename boost::numeric::odeint::is_resizeable< V >::type>
struct state_wrapper;

//two standard implementations, with and without resizing depending on is_resizeable< StateType >

template< class V >
struct state_wrapper< V , boost::true_type > // with resizing
{
    typedef state_wrapper< V , boost::true_type > state_wrapper_type;
    //typedef typename V::value_type value_type;
    typedef boost::true_type is_resizeable;

    V m_v;

    template< class StateIn >
    bool same_size( const StateIn &x ) const
    {
        //standard implementation relies on boost.range
        return ( boost::size( m_v ) == boost::size( x ) );
    }

    template< class StateIn >
    bool resize( const StateIn &x )
    {
        //standard resizing done like for std::vector
        if( !same_size( x ) )
        {
            m_v.resize( boost::size( x ) );
            return true;
        } else
            return false;
    }
};


template< class V >
struct state_wrapper< V , boost::false_type > // without resizing
{
    typedef state_wrapper< V , boost::false_type > state_wrapper_type;
    //typedef typename V::value_type value_type;
    typedef boost::false_type is_resizeable;

    V m_v;

    //no resize method
};

}
}
}



#endif // BOOST_NUMERIC_ODEINT_UTIL_STATE_WRAPPER_HPP_INCLUDED
