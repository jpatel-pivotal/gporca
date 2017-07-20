//---------------------------------------------------------------------------
//	Greenplum Database
//	Copyright (C) 2013 EMC Corp.
//
//	@filename:
//		CXformLeftSemiJoin2LeftSemiJoinWithLimit.h
//
//	@doc:
//		Transform left semi join to cross product
//---------------------------------------------------------------------------
#ifndef GPOPT_CXformLeftSemiJoin2LeftSemiJoinWithLimit_H
#define GPOPT_CXformLeftSemiJoin2LeftSemiJoinWithLimit_H

#include "gpos/base.h"
#include "gpopt/xforms/CXformExploration.h"

namespace gpopt
{
	using namespace gpos;

	//---------------------------------------------------------------------------
	//	@class:
	//		CXformLeftSemiJoin2LeftSemiJoinWithLimit
	//
	//	@doc:
	//		Transform left semi join to cross product
	//
	//---------------------------------------------------------------------------
	class CXformLeftSemiJoin2LeftSemiJoinWithLimit : public CXformExploration
	{

		private:

			// private copy ctor
			CXformLeftSemiJoin2LeftSemiJoinWithLimit(const CXformLeftSemiJoin2LeftSemiJoinWithLimit &);

		public:

			// ctor
			explicit
			CXformLeftSemiJoin2LeftSemiJoinWithLimit(IMemoryPool *pmp);

			// dtor
			virtual
			~CXformLeftSemiJoin2LeftSemiJoinWithLimit() {}

			// ident accessors
			virtual
			EXformId Exfid() const
			{
				return ExfLeftSemiJoin2LeftSemiJoinWithLimit;
			}

			// return a string for xform name
			virtual
			const CHAR *SzId() const
			{
				return "CXformLeftSemiJoin2LeftSemiJoinWithLimit";
			}

            // Compatibility function for splitting limit
            virtual
            BOOL FCompatible(CXform::EXformId exfid)
            {
                return (CXform::ExfLeftSemiJoin2LeftSemiJoinWithLimit != exfid);
            }

			// compute xform promise for a given expression handle
			virtual
			EXformPromise Exfp(CExpressionHandle &exprhdl) const;

			// actual transform
			void Transform
					(
					CXformContext *pxfctxt,
					CXformResult *pxfres,
					CExpression *pexpr
					)
					const;

	}; // class CXformLeftSemiJoin2LeftSemiJoinWithLimit

}


#endif // !GPOPT_CXformLeftSemiJoin2LeftSemiJoinWithLimit_H

// EOF
