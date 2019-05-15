/* -------------------------------------------------------------------------- *
 * OpenSim Moco: MocoDirectCollocationSolver.cpp                              *
 * -------------------------------------------------------------------------- *
 * Copyright (c) 2019 Stanford University and the Authors                     *
 *                                                                            *
 * Author(s): Christopher Dembia                                              *
 *                                                                            *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may    *
 * not use this file except in compliance with the License. You may obtain a  *
 * copy of the License at http://www.apache.org/licenses/LICENSE-2.0          *
 *                                                                            *
 * Unless required by applicable law or agreed to in writing, software        *
 * distributed under the License is distributed on an "AS IS" BASIS,          *
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.   *
 * See the License for the specific language governing permissions and        *
 * limitations under the License.                                             *
 * -------------------------------------------------------------------------- */

#include "MocoDirectCollocationSolver.h"

using namespace OpenSim;

void MocoDirectCollocationSolver::constructProperties() {
    constructProperty_num_mesh_points(100);
    constructProperty_mesh();
    constructProperty_verbosity(2);
    constructProperty_transcription_scheme("trapezoidal");
    constructProperty_dynamics_mode("explicit");
    constructProperty_optim_solver("ipopt");
    constructProperty_optim_max_iterations(-1);
    constructProperty_optim_convergence_tolerance(-1);
    constructProperty_optim_constraint_tolerance(-1);
    constructProperty_optim_hessian_approximation("limited-memory");
    constructProperty_optim_ipopt_print_level(-1);
    constructProperty_guess_file("");
    constructProperty_velocity_correction_bounds({-0.1, 0.1});
    constructProperty_minimize_lagrange_multipliers(false);
    constructProperty_lagrange_multiplier_weight(1.0);

    // This is empty to allow user input error checking.
    constructProperty_enforce_constraint_derivatives();
}

void MocoDirectCollocationSolver::setMesh(std::vector<double> const mesh) {
    for(int i = 0; i < (int) mesh.size(); ++i) {
        this->set_mesh(i, mesh[i]);
    }

}
