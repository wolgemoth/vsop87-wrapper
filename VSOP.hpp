#ifndef LOUIERIKSSON_VSOP_HPP
#define LOUIERIKSSON_VSOP_HPP

#include <glm/detail/qualifier.hpp>
#include <vsop87a_full.h>

namespace LouiEriksson {
	
	/**
	 * @mainpage Version 1.0.0
	 *
	 * @brief Class representing the VSOP astronomical coordinate system.
	 *
	 * The VSOP class provides functions for obtaining position information of celestial bodies.
	 *
	 * @tparam T The underlying type of the vector components.
	 * @tparam Q The precision of the vector components.
	 */
	template <typename T, glm::precision Q>
	struct VSOP final {
	
	private:
	
		/**
		 * @brief Changes the handedness of a 3D vector.
		 *
		 * This function takes a 3D vector and returns a new vector with changed handedness.
		 *
		 * @tparam T The underlying type of the vector components.
		 * @tparam P The precision of the vector components.
		 * @param[in] _vec The input vector.
		 * @return The new vector with changed handedness.
		 */
		template<typename T, glm::precision Q>
		static constexpr glm::vec<3, T, Q> ChangeHandedness(const glm::vec<3, T, Q>& _vec) {
			return { -_vec.x, _vec.z, _vec.y };
		}
		
	public:
		
		struct Position final {
		
		private:
			
			glm::vec<3, T, Q> m_Spherical;
			glm::vec<3, T, Q> m_Cartesian;
			glm::qua<   T, Q> m_Rotation;
			
		public:
			
			constexpr const glm::vec<3, T, Q>& Spherical() const noexcept { return m_Spherical; }
			constexpr const glm::vec<3, T, Q>& Cartesian() const noexcept { return m_Cartesian; }
			constexpr const glm::qua<   T, Q>&  Rotation() const noexcept { return m_Rotation;  }
			
			constexpr Position(const glm::vec<3, T, Q>& _spherical, const glm::vec<3, T, Q>& _cartesian, const glm::vec<3, T, Q>& _rotation) noexcept :
				m_Spherical(_spherical),
				m_Cartesian(_cartesian),
				m_Rotation (_rotation ) {}
			
			constexpr Position() noexcept :
				m_Spherical{},
				m_Cartesian{},
				m_Rotation {} {}
		};
		
		struct V87 final {
			
			struct A final {
				
				static Position GetSol() {
					return {
						{},
						{ 0.0, 0.0, 0.0 },
						{}
					};
				}
				
				static Position GetMercury(const double& _time) {
					
					double tmp[3];
					
				    vsop87a_full::getMercury(_time, tmp);
					
					return {
						{},
						{ ChangeHandedness<T, Q>({ tmp[0], tmp[1], tmp[2] }) },
						{}
					};
				}
				
				static Position GetVenus(const double& _time) {
					
					double tmp[3];
					
				    vsop87a_full::getVenus(_time, tmp);
					
					return {
						{},
						{ ChangeHandedness<T, Q>({ tmp[0], tmp[1], tmp[2] }) },
						{}
					};
				}
				
				static Position GetEarth(const double& _time) {
					
					double tmp[3];
					
				    vsop87a_full::getEarth(_time, tmp);
					
					return {
						{},
						{ ChangeHandedness<T, Q>({ tmp[0], tmp[1], tmp[2] }) },
						{}
					};
				}
				
				static Position GetEMB(const double& _time) {
					
					double tmp[3];
					
				    vsop87a_full::getEmb(_time, tmp);
					
					return {
						{},
						{ ChangeHandedness<T, Q>({ tmp[0], tmp[1], tmp[2] }) },
						{}
					};
				}
				
				static Position GetMoon(const Position& _earth, const Position& _emb) {
					
					auto e1 = ChangeHandedness<double, Q>(_earth.Cartesian());
					auto e2 = ChangeHandedness<double, Q>(  _emb.Cartesian());
					
					double tmp[3];
					
				    vsop87a_full::getMoon(&e1[0], &e2[0], tmp);
					
					return {
						{},
						{ ChangeHandedness<T, Q>({ tmp[0], tmp[1], tmp[2] }) },
						{},
					};
				}
				
				static Position GetMars(const double& _time) {
					
					double tmp[3];
					
				    vsop87a_full::getMars(_time, tmp);
					
					return {
						{},
						{ ChangeHandedness<T, Q>({ tmp[0], tmp[1], tmp[2] }) },
						{}
					};
				}
				
				static Position GetJupiter(const double& _time) {
					
					double tmp[3];
					
				    vsop87a_full::getJupiter(_time, tmp);
					
					return {
						{},
						{ ChangeHandedness<T, Q>({ tmp[0], tmp[1], tmp[2] }) },
						{}
					};
				}
				
				static Position GetSaturn(const double& _time) {
					
					double tmp[3];
					
				    vsop87a_full::getSaturn(_time, tmp);
					
					return {
						{},
						{ ChangeHandedness<T, Q>({ tmp[0], tmp[1], tmp[2] }) },
						{}
					};
				}
				
				static Position GetUranus(const double& _time) {
					
					double tmp[3];
					
				    vsop87a_full::getUranus(_time, tmp);
					
					return {
						{},
						{ ChangeHandedness<T, Q>({ tmp[0], tmp[1], tmp[2] }) },
						{}
					};
				}
				
				static Position GetNeptune(const double& _time) {
					
					double tmp[3];
					
				    vsop87a_full::getNeptune(_time, tmp);
					
					return {
						{},
						{ ChangeHandedness<T, Q>({ tmp[0], tmp[1], tmp[2] }) },
						{}
					};
				}
			};
		};
	};
	
} // LouiEriksson

#endif //LOUIERIKSSON_VSOP_HPP