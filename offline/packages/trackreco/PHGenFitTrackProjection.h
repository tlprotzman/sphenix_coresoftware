/*!
 *  \file		PHGenFitTrackProjection.h
 *  \brief		Projects into calorimeters and fills track cal fields using GenFit
 *  \author		Haiwang Yu <yuhw@nmsu.edu>
 */

#ifndef G4HOUGH_PHGENFITTRACKPROJECTION_H
#define G4HOUGH_PHGENFITTRACKPROJECTION_H

#include <trackbase_historic/SvtxTrack.h>

#include <fun4all/SubsysReco.h>

// std includes
#include <vector>
#include <string>

// forward declarations
class PHCompositeNode;

namespace PHGenFit {
	class Fitter;
}

/// \class PHGenFitTrackProjection
///
/// \brief Projects into calorimeters and fills track cal fields
///
class PHGenFitTrackProjection : public SubsysReco
{

 public:
 
  PHGenFitTrackProjection(const std::string &name = "PHGenFitTrackProjection", const int pid_guess = 211);
  virtual ~PHGenFitTrackProjection() {}
		
  int Init(PHCompositeNode *topNode);
  int InitRun(PHCompositeNode *topNode);
  int process_event(PHCompositeNode *topNode);
  int End(PHCompositeNode *topNode);

	int get_pid_guess() const {
		return _pid_guess;
	}

	void set_pid_guess(int pidGuess) {
		_pid_guess = pidGuess;
	}


 private:

  PHGenFit::Fitter * _fitter;
  int _pid_guess;

  int _num_cal_layers;
  std::vector<SvtxTrack::CAL_LAYER> _cal_types;
  std::vector<std::string> _cal_names;
  std::vector<float> _cal_radii;
};

#endif // __PHGENFITTRACKPROJECTION_H__
