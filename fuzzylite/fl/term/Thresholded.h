/*   Copyright 2013 Juan Rada-Vilela

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

/*
 * Thresholded.h
 *
 *  Created on: 30/11/2012
 *      Author: jcrada
 */

#ifndef FL_THRESHOLDED_H
#define FL_THRESHOLDED_H

#include "fl/term/Term.h"

namespace fl {
    class TNorm;

    //TODO: Rename to Activated
    class FL_EXPORT Thresholded : public Term {
    protected:
        const Term* _term;
        scalar _threshold; //TODO: rename to degree
        const TNorm* _activation;

    public:
        Thresholded(const Term* term = NULL, scalar threshold = 1.0,
                const TNorm* activationOperator = NULL);

        virtual ~Thresholded();

        virtual std::string className() const;
        virtual std::string parameters() const;
        virtual void configure(const std::string& parameters);

        virtual scalar membership(scalar x) const;
        virtual std::string toString() const;

        virtual void setTerm(const Term* term);
        virtual const Term* getTerm() const;
        
        virtual void setThreshold(scalar threshold);
        virtual scalar getThreshold() const;

        virtual void setActivation(const TNorm* activation);
        virtual const TNorm* getActivation() const;

        virtual Thresholded* copy() const;
    };

}
#endif /* FL_THRESHOLDED_H */
