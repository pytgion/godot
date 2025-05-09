## SOTERIO ENGINE  

#### Custom Godot Fork – Internal Development Build

Soterio Engine is our customized version of the Godot Engine (https://godotengine.org), purpose-built for Soterio Bladesmith.


------------------------------------------------------------
🔧 Current Modifications

- **Rendering Enhancements**  
  Improved backend for realistic visuals and cinematic lighting.

- **Custom Physics Module**
  Built to simulate complex materials, structural deformations, and real-time FEM-like behavior.

- **Workflow & Build Optimizations**  
  Faster iteration, minimal friction for daily dev, cleaner editor experience.

------------------------------------------------------------
🚀 Getting Started

Environment Setup

1. Clone the repository and cd into the directory.
2. Build instructions:

   - Windows:
     `scons platform=windows vsproj=yes dev_build=yes`

   - Linux:
     [Official Documentation](
     https://docs.godotengine.org/en/stable/contributing/development/configuring_an_ide/visual_studio_code.html)

Tip: Use dev_build=yes for debugging tools and internal features.

------------------------------------------------------------
📁 Project Configuration

- Use the `soterio_project.json` template for new project setups.

------------------------------------------------------------
📝 Development TODOs

- [ ] Custom Shader Pipeline (SoterioMaterial)
- [ ] Memory Optimizations for Large Environments
- [ ] Input System Refactor for Advanced Controls
<!-- - [ ] Extended Animation Blending System -->
- [ ] Custom Asset Importers (.sotmesh, .sotmat)
- [ ] Rendering Performance Profiling + Optimization
- [ ] Internal Documentation for Engine API Differences

------------------------------------------------------------
👥 Team Workflow & Standards

Branch Naming:
  - feature/<desc>
  - bugfix/<ticket-id>
  - optimization/<module>

Commits:
  - Reference internal issue/ticket ID where applicable
  - Write meaningful and scoped messages

Reviews:
  - All engine changes require peer review and testing before merging.

Build Distribution:
  - Internal CI drops weekly development builds to /ci_builds/soterio

------------------------------------------------------------
📢 Contact & Support

For questions, issues, or suggestions:
- Contact the project lead

------------------------------------------------------------
🤝 Credits

This project builds on the open-source Godot Engine (https://godotengine.org).  
We are grateful to the Godot team and community — our work would not be possible without their foundation.
